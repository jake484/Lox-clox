#ifndef clox_compiler_h
#define clox_compiler_h
#include "object.h"
#include "vm.h"
#include "chunk.h"
#include "scanner.h"
bool compile(const char* source, Chunk* chunk);
static void consume(TokenType type, const char *message);
static void emitBytes(uint8_t byte1, uint8_t byte2);
static void emitConstant(Value value);
static void emitReturn();
static void endCompiler();
static void advance();
static void expression();
#endif