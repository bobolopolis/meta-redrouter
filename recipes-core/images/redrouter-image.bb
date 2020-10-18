SUMMARY = "Image for building a PiPoint"

LICENSE = "MIT"

#    read-only-rootfs
IMAGE_FEATURES += " \
    ssh-server-openssh \
"

IMAGE_INSTALL = " \
    packagegroup-core-boot \
    packagegroup-base-extended \
    ${CORE_IMAGE_EXTRA_INSTALL} \
"
# Future possibilities:
# kea
IMAGE_INSTALL += " \
    chrony \
    chronyc \
    dnsmasq \
    hostapd \
    nftables \
"
# Debug
IMAGE_INSTALL += " \
    dmidecode \
    htop \
    lmsensors \
    lmsensors-sensors \
    lmsensors-sensorsdetect \
    util-linux \
"
IMAGE_LINGUAS = "en-us"

inherit core-image
