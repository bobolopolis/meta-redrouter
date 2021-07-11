require recipes-kernel/linux/linux-yocto.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

DEPENDS += "lz4-native"

SRC_URI = " \
    git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;protocol=https;nocheckout=1;name=machine;branch=linux-5.4.y \
    git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-5.4;destsuffix=kernel-meta \
    file://defconfig \
"
SRCREV_machine = "4e85f8a712cddf2ceeaac50a26b239fbbcb7091f"
SRCREV_meta = "19738ca97b999a3b150e2d34232bb44b6537348f"

LINUX_VERSION = "5.4.109"
PV = "${LINUX_VERSION}"
LINUX_VERSION_EXTENSION = "-redrouter"

COMPATIBLE_MACHINE = "redrouterx86-64|apu2"
