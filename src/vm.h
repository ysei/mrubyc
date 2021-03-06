/*! @file
  @brief
  mruby bytecode executor.

  <pre>
  Copyright (C) 2015 Kyushu Institute of Technology.
  Copyright (C) 2015 Shimane IT Open-Innovation Center.

  This file is distributed under BSD 3-Clause License.

  Fetch mruby VM bytecodes, decode and execute.

  </pre>
*/

#ifndef MRUBYC_SRC_VM_H_
#define MRUBYC_SRC_VM_H_

#include <stdint.h>
#include "value.h"
#include "vm_config.h"

#ifdef __cplusplus
extern "C" {
#endif


//================================================================
/*!@brief

*/
typedef struct IREP {
  int16_t unused;       //! unused flag
  struct IREP *next;         //! irep linked list

  uint8_t *code;
  mrb_object *ptr_to_pool;
  uint8_t *ptr_to_sym;

  int16_t nlocals;
  int16_t nregs;
  int16_t rlen;
  int16_t ilen;

  int16_t iseq;

} mrb_irep;


//================================================================
/*!@brief

*/
typedef struct CALLINFO {
  mrb_irep *pc_irep;
  int pc;
  int reg_top;
} mrb_callinfo;


//================================================================
/*!@brief

*/
typedef struct VM {
  struct VM *next;  // linked list
  mrb_irep *irep;     // irep linked list
  int16_t priority;
  char *mrb;

  mrb_irep *pc_irep;  // PC
  int16_t pc;       // PC

  int reg_top;
  mrb_value regs[MAX_REGS_SIZE];
  int callinfo_top;
  mrb_callinfo callinfo[MAX_CALLINFO_SIZE];

  mrb_class *target_class;
  mrb_object *top_self;  // ?

} mrb_vm;



  //int check_str_4(char *s1, char *s2);
  //int get_int_4(char *s);
  //int get_int_2(char *s);

mrb_irep *new_irep(void);


struct VM *vm_open(void);
void vm_close(struct VM *vm);
void vm_boot(struct VM *vm);
int vm_run_step(struct VM *vm);


#ifdef __cplusplus
}
#endif
#endif
