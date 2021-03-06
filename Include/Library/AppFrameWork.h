
#pragma once
#include <Uefi.h>
#include <Library/UefiLib.h>

typedef struct _EFI_APP_FRAMEWORK_TABLE EFI_APP_FRAMEWORK_TABLE;

typedef struct{
  UINTN APP_OPERATIONS_NONE : 1;
  UINTN APP_OPERATIONS_PRINT_TEXT : 1;
  UINTN APP_OPERATIONS_PRINT_MENU : 1;
  UINTN APP_OPERATIONS_PRINT_HELP : 1;
}APP_OPERATIONS;

typedef
EFI_STATUS
(*APP_FRAMWORK_INI) (
  UINTN Argc, 
  CHAR16 **Argv
  );

typedef
EFI_STATUS
(*APP_FRAMWORK_HELP) (
  );

struct _EFI_APP_FRAMEWORK_TABLE{
  APP_FRAMWORK_INI Init;
  APP_FRAMWORK_HELP AppPrintHelp;
  APP_OPERATIONS  Operations;
  VOID *PROTOCOL1;
  VOID *PROTOCOL2;
  VOID (*OP1)(VOID *Para1);
};


EFI_STATUS
EFIAPI
ParseCommandLine(
  IN UINTN Argc,
  IN CHAR16 **Argv,
  EFI_APP_FRAMEWORK_TABLE *FtHandle
  );

