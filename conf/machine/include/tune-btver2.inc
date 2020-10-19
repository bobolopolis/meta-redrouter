# Settings for the GCC(1) cpu-type "btver2":
#
#     AMD Famil 16h CPU with 64-bit extensions, MOVBE, F16C, BMI, AVX, PCLMUL,
#     CX16, ABM, AES, MMX, SSE, SSE2, SSE3, SSSE3, SSE4a, SSE4.1, SSE4.2, and
#     POPCNT instruction set support.
#
# This tune is recommended for AMD Family 16h CPUs (and beyond).
#
DEFAULTTUNE ?= "btver2-64"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/tune-core2.inc

# Extra tune features
TUNEVALID[btver2] = "Enable AMD Family 16h specific processor optimizations"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'btver2', ' -march=btver2', '', d)}"

# Extra tune selections
AVAILTUNES += "btver2-64"
TUNE_FEATURES_tune-btver2-64 = "${TUNE_FEATURES_tune-x86-64} btver2"
BASE_LIB_tune-btver2-64 = "lib64"
TUNE_PKGARCH_tune-btver2-64 = "btver2-64"
PACKAGE_EXTRA_ARCHS_tune-btver2-64 = "${PACKAGE_EXTRA_ARCHS_tune-core2-64} btver2-64"
QEMU_EXTRAOPTIONS_btver2-64 = " -cpu EPYC,check=false"
