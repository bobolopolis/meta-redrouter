IMAGE_CMD_red() {
    rm -rf ${WORKDIR}/red
    install -d ${WORKDIR}/red

    #mksquashfs ${IMAGE_ROOTFS} ${IMAGEDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.squashfs-lz4 ${EXTRA_IMAGECMD} -noappend -comp lz4
    mksquashfs ${IMAGE_ROOTFS} ${WORKDIR}/red/red.squashfs-lz4 -noappend -comp lz4
    dd if=/dev/zero of=${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.red seek=${ROOTFS_SIZE} count=0 bs=1024
    #mkfs.btrfs ${EXTRA_IMAGECMD} -r ${IMAGE_ROOTFS} ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.red
    mkfs.btrfs ${EXTRA_IMAGECMD} -r ${WORKDIR}/red ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.red
}
do_image_red[depends] += "squashfs-tools-native:do_populate_sysroot"
do_image_red[depends] += "btrfs-tools-native:do_populate_sysroot"
