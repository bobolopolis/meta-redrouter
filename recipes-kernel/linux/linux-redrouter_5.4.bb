require recipes-kernel/linux/linux-yocto.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

DEPENDS += "lz4-native"

SRC_URI = " \
    git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;protocol=https;nocheckout=1;name=machine;branch=linux-5.4.y \
    git://git.yoctoproject.org/yocto-kernel-cache;type=kmeta;name=meta;branch=yocto-5.4;destsuffix=kernel-meta \
    file://defconfig \
"
SRCREV_machine = "bdc3a8f6a8e8b798c46683a98b97d52b3a5708e4"
SRCREV_meta = "0d860e075788a92601dff3eb9b615ee41e465040"

LINUX_VERSION = "5.4.66"
PV = "${LINUX_VERSION}"
LINUX_VERSION_EXTENSION = "-redrouter"

COMPATIBLE_MACHINE = "redrouterx86-64"
