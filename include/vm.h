#ifndef clox_vm_h
#define clox_vm_h
#include "compiler.h"
#include "object.h"
#include "table.h"
#include "value.h"
#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

typedef struct
{
    ObjClosure *closure;
    uint8_t *ip;
    Value *slots;
} CallFrame;

typedef enum
{
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

typedef struct
{
    CallFrame frames[FRAMES_MAX];
    int frameCount;
    Value stack[STACK_MAX];
    Value *stackTop;
    ObjUpvalue *openUpvalues;

    size_t bytesAllocated;
    size_t nextGC;
    Obj *objects;
    Table globals;
    Table strings;
    ObjString *initString;
    int grayCount;
    int grayCapacity;
    Obj **grayStack;
} VM;

extern VM vm;

void initVM();
void freeVM();
InterpretResult interpret(const char *source);
static InterpretResult run();
void push(Value value);
Value pop();
#endif