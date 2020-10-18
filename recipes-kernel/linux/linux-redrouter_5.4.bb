require recipes-kernel/linux/linux-yocto.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

DEPENDS += "lz4-native"

SRC_URI = " \
    git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;protocol=https;nocheckout=1;name=machine;branch=linux-5.4.y \
    git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-5.4;destsuffix=kernel-meta \
    file://defconfig \
"
SRCREV_machine = "52f6ded2a377ac4f191c84182488e454b1386239"
SRCREV_meta = "bb39fa8ebe05b1a0663cb7e04b83c5708a43e168"

LINUX_VERSION = "5.4.72"
PV = "${LINUX_VERSION}"
LINUX_VERSION_EXTENSION = "-redrouter"

COMPATIBLE_MACHINE = "redrouterx86-64"
