#ifdef PNEUMATICA_EXPORTS
#define PNEUMO_API __declspec(dllexport)
#else
#define PNEUMO_API __declspec(dllimport)
#endif