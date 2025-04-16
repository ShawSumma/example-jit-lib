
#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

$includes

#define error(...) (fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), exit(1))

$globals

#define $next(type) (* (type *) ((size_t) $scope_bytecode.mem + ($scope_index += sizeof(type)) - sizeof(type)))

void $scope_run($scope_ctx_t *ctx, const $scope_buf_t $scope_bytecode) {
    (void) ctx;
    
    $pre

    size_t $scope_index = 0;

    while ($scope_index < $scope_bytecode.len) {
        size_t $scope_index_base = $scope_index;
        $scope_opcode_t op = $next($scope_opcode_t);
        switch(op) {
            $cases
            default: {
                error("unknown opcode: %zu (byte %zu)\n", (size_t) op, $scope_index_base);
            }
        }
    }
    
    $post
}
