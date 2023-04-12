#ifndef ____DATA_MODEL_IMPL_H__
#define ____DATA_MODEL_IMPL_H__

typedef struct {
    const unsigned char index;
    const char* name;
} base_data_model_t;

#define DM_BASE_NAME(name)                \
                        __DataModel_##name 

#ifdef _MSC_VER
#pragma section("DataModelTab$f",read)
#endif /* _MSC_VER */

#ifdef _MSC_VER
#define DATA_MODEL(name, type)                                                          \
                typedef void (*__DataModel_##name##_set)(type ctx);   \
                typedef type (*__DataModel_##name##_get)(void);             \
                const char __DataModel_##type##_name[] = #name;             \
                typedef struct                                              \
                {                                                           \
                    base_data_model_t base;                                 \
                    type *ctx;                                              \
                    __DataModel_##name##_set set;                           \
                    __DataModel_##name##_get get;                           \
                } __DataModel_##name##_t;                                   \
                void __DataModel_##name##_set_impl(type ctx){        \
                    type a = ctx;                                                            \
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
#define SHELL_FUNCTION_EXPORT_CMD(name, cmd, desc)                                  \
                const char __fsym_##cmd##_name[] __attribute__((section(".rodata.name"))) = #cmd;    \
                __attribute__((used)) const struct sh_syscall __fsym_##cmd __attribute__((section("FSymTab")))= \
                {                           \
                    __fsym_##cmd##_name,    \
                    (syscall_func)&name     \
                };
#endif

#define EXPORT_DATA_MODEL(name, type)                           \
    typedef void (*__DataModel_##name##_set)(type ctx);         \
    typedef type (*__DataModel_##name##_get)(void);             \
    typedef struct                                              \
    {                                                           \
        base_data_model_t base;                                 \
        type *ctx;                                              \
        __DataModel_##name##_set set;                           \
        __DataModel_##name##_get get;                           \
    } __DataModel_##name##_t;                                   \
    extern const __DataModel_##name##_t DM_BASE_NAME(name);

#define DATA_MODEL_SET(name, ctx)			\
	DM_BASE_NAME(name).set(ctx)

#define DATA_MODEL_GET(name)			\
	DM_BASE_NAME(name).get()

#endif
