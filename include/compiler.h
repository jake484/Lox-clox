#ifndef clox_compiler_h
#define clox_compiler_h
#include "object.h"
#include "vm.h"
#include "chunk.h"
#include "scanner.h"
ObjFunction *compile(const char *source);
void markCompilerRoots();
static void consume(TokenType type, const char *message);
static void emitBytes(uint8_t byte1, uint8_t byte2);
static void emitConstant(Value value);
static void emitReturn();
static ObjFunction *endCompiler();

static void advance();
static void expression();
static void statement();
static void declaration();
static bool match(TokenType type);
static bool check(TokenType type);
static int emitJump(uint8_t instruction);
static void emitLoop(int loopStart);
static void patchJump(int offset);

#endif