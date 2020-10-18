# Settings for the GCC(1) cpu-type "nehalem":
#
#     Intel Nehalem CPU with 64-bit extensions, MMX, SSE, SSE2, SSE3, SSSE3, SSE4.1,
#     SSE4.2 and POPCNT instruction set support.
#
# This tune is recommended for Intel Nehalem and Silvermont (e.g. Bay Trail) CPUs
# (and beyond).
#

# Settings for redrectangle platforms. Supported CPUs are:
# AMD GX-412TC: Jaguar microarchitecture, AMD Family 16h cores. GCC CPU type
# btver2
#
# Extension	GX-412TC
# MMX		X
# SSE		X
# SSE2		X
# SSE3		X
# SSSE3		X
# SSE4a		X
# SSE4.1	X
# SSE4.2	X
# AVX		X
# AES		X
# PCLMUL	X
# F16C		X
# ABM		X
# BMI		X
#
# CX16		X
# MOVBE		X

DEFAULTTUNE ?= "red-64"

# Include the previous tune to pull in PACKAGE_EXTRA_ARCHS
require conf/machine/include/tune-core2.inc

# Extra tune features
TUNEVALID[red] = "Enable redrouter specific processor optimizations"
#TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'red', ' -march=x86-64 -mtune=generic -mfpmath=sse -mmmx -msse -msse2 -msse3 -mssse3 -msse4a -msse4.1 -msse4.2 -mavx -maes -mpclmul -mf16c -mabm -mbmi -mcx16 -mmovbe', '', d)}"
#TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'red', ' -march=x86-64 -mtune=generic -mfpmath=sse -mmmx -msse -msse2 -msse3 -mssse3 -msse4a -msse4.1 -msse4.2 -maes -mpclmul -mabm -mbmi -mcx16 -mmovbe', '', d)}"
TUNE_CCARGS .= "${@bb.utils.contains('TUNE_FEATURES', 'red', ' -march=x86-64 -mtune=generic -mfpmath=sse -mmmx -msse -msse2', '', d)}"

# Extra tune selections
AVAILTUNES += "red-64"
TUNE_FEATURES_tune-red-64 = "${TUNE_FEATURES_tune-x86-64} red"
BASE_LIB_tune-red-64 = "lib64"
TUNE_PKGARCH_tune-red-64 = "red-64"
PACKAGE_EXTRA_ARCHS_tune-red-64 = "${PACKAGE_EXTRA_ARCHS_tune-core2-64} red-64"
QEMU_EXTRAOPTIONS_red-64 = " -cpu SandyBridge,check=false"
