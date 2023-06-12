#ifndef ____DATA_MODEL_IMPL_H__
#define ____DATA_MODEL_IMPL_H__

#include <assert.h>
#include "m2v_ipc.h"

typedef struct {
    const unsigned int index;
    const char* name;
} base_data_model_t;

typedef int (*base_view_cb_func_t)(void *);

typedef struct                                              
{                                                           
    base_data_model_t base;                                 
    void *ctx;                                              
    void *set;                          
    void *get;                          
    void **view_cb;                  
} __DataModel_BASE_t;                                  

#define DM_BASE_NAME(name)                \
                        __DataModel_##name 

#ifdef _MSC_VER
#pragma section("DataModelTab$f",read)
#endif /* _MSC_VER */

#ifdef _MSC_VER
#define DATA_MODEL(name, type)                                                          \
                typedef void (*__DataModel_##name##_set)(type ctx, unsigned int event);   \
                typedef type (*__DataModel_##name##_get)(void);             \
                const char __DataModel_##type##_name[] = #name;             \
                typedef struct                                              \
                {                                                           \
                    base_data_model_t base;                                 \
                    type *ctx;                                              \
                    __DataModel_##name##_set set;                           \
                    __DataModel_##name##_get get;                           \
                } __DataModel_##name##_t;                                   \
                void __DataModel_##name##_set_impl(type ctx, unsigned int event){        \
                    *((__DataModel_##name##_t *) base)->ctx = ctx;      \
                    if((*((__DataModel_##name##_t *) base)->view_cb) != NULL){     \
                        (*((__DataModel_##name##_t *) base)->view_cb)(*((__DataModel_##name##_t *) base)->ctx);         \
                    }               \
                }                                                                                   \
                type __DataModel_##name##_get_impl(void){                   \
                    type a = {1};           \
                    return a;                                                              \
                }                                                                                   \
                __declspec(allocate("DataModelTab$f"))                      \
                const __DataModel_##name##_t __DataModel_##name  =                         \
                {                                               \
                    {__COUNTER__, __DataModel_##type##_name,},                                \
                    &name,                               \
                    __DataModel_##name##_set_impl,                                          \
                    __DataModel_##name##_get_impl                                           \
                };
#pragma comment(linker, "/merge:DataModelTab=mytext")

#else
#define DATA_MODEL(name, type)                                                          \
                const char __DataModel_##type##_name[] __attribute__((section(".dmro.name"))) = #name;             \
                typedef void (*__DataModel_##name##_set)(const base_data_model_t *base, type ctx, unsigned int event);   \
                typedef type (*__DataModel_##name##_get)(const base_data_model_t *base);             \
                typedef int (*__DataModel_##name##view_cb)(type *ctx);             \
                typedef struct                                              \
                {                                                           \
                    base_data_model_t base;                                \
                    type *ctx;                                              \
                    __DataModel_##name##_set set;                           \
                    __DataModel_##name##_get get;                           \
                    __DataModel_##name##view_cb *view_cb;                   \
                } __DataModel_##name##_t;                                   \
                void __DataModel_##name##_set_impl(const base_data_model_t *base, type ctx, unsigned int event){        \
                    *((__DataModel_##name##_t *) base)->ctx = ctx;      \
                    if(event > 255){                        \
                        assert(0);\
                    }   \
                    m2v_ipc_write((unsigned char)event);\
                }                                       \
                type __DataModel_##name##_get_impl(const base_data_model_t *base){                   \
                    return *(((__DataModel_##name##_t *) base)->ctx);                                                              \
                }        \
                __DataModel_##name##view_cb view_##name##_cb_impl = NULL;                        \
                __attribute__((used)) const __DataModel_##name##_t DM_BASE_NAME(name) __attribute__((section("DataModelTab"))) =   \
                {                                                                           \
                    {__COUNTER__, __DataModel_##type##_name},                               \
                    &name,                                                                  \
                    __DataModel_##name##_set_impl,                                          \
                    __DataModel_##name##_get_impl,                                          \
                    &view_##name##_cb_impl                                                   \
                };
#endif

#define EXPORT_DATA_MODEL(name, type)                           \
    typedef void (*__DataModel_##name##_set)(const base_data_model_t *base, type ctx, unsigned int event);         \
    typedef type (*__DataModel_##name##_get)(const base_data_model_t *base);             \
    typedef int (*__DataModel_##name##view_cb)(type *ctx);             \
    typedef struct                                              \
    {                                                           \
        base_data_model_t base;                                 \
        type *ctx;                                              \
        __DataModel_##name##_set set;                           \
        __DataModel_##name##_get get;                           \
        __DataModel_##name##view_cb *view_cb;                   \
    } __DataModel_##name##_t;                                   \
    extern const __DataModel_##name##_t DM_BASE_NAME(name);

#define DATA_MODEL_SET(name, ctx)			\
	DM_BASE_NAME(name).set(&DM_BASE_NAME(name).base, ctx, DM_BASE_NAME(name).base.index)

#define DATA_MODEL_GET(name)			\
	DM_BASE_NAME(name).get(&DM_BASE_NAME(name).base)


#define view_DataModel_register(name, func)         \
    *(DM_BASE_NAME(name).view_cb) = func

#endif
