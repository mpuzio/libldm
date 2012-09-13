/* libldm
 * Copyright 2012 Red Hat Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBLDM_LDM_H__
#define LIBLDM_LDM_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define LDM_ERROR ldm_error_quark()
GQuark ldm_error_quark(void);

/**
 * LDMError:
 * @LDM_ERROR_INTERNAL: An internal error
 * @LDM_ERROR_IO: There was an IO error accessing a device
 * @LDM_ERROR_NOT_LDM: The device is not part of an LDM disk group
 * @LDM_ERROR_INVALID: The LDM metadata is corrupt
 * @LDM_ERROR_NOTSUPPORTED: Unsupported LDM metadata
 * @LDM_ERROR_MISSING_DISK: A disk is missing from a disk group
 * @LDM_ERROR_EXTERNAL: An error reported by an external library
 */
typedef enum {
    LDM_ERROR_INTERNAL,
    LDM_ERROR_IO,
    LDM_ERROR_NOT_LDM,
    LDM_ERROR_INVALID,
    LDM_ERROR_INCONSISTENT,
    LDM_ERROR_NOTSUPPORTED,
    LDM_ERROR_MISSING_DISK,
    LDM_ERROR_EXTERNAL
} LDMError;

#define LDM_TYPE_ERROR (ldm_error_get_type())

GType ldm_error_get_type(void);

/* LDM */

#define LDM_TYPE            (ldm_get_type())
#define LDM(obj)            (G_TYPE_CHECK_INSTANCE_CAST \
                                        ((obj), LDM_TYPE, LDM))
#define LDM_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST \
                                        ((klass), LDM_TYPE, LDMClass))
#define IS_LDM(obj)         (G_TYPE_CHECK_INSTANCE_TYPE \
                                        ((obj), LDM_TYPE))
#define IS_LDM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE \
                                        ((klass), LDM_TYPE))
#define LDM_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS \
                                        ((obj), LDM_TYPE, LDMClass))
typedef struct _LDMPrivate LDMPrivate;

typedef struct _LDM LDM;
struct _LDM
{
    GObject parent;
    LDMPrivate *priv;
};

typedef struct
{
    GObjectClass parent_class;
} LDMClass;

/* LDMDiskGroup */

#define LDM_TYPE_DISK_GROUP            (ldm_disk_group_get_type())
#define LDM_DISK_GROUP(obj)            (G_TYPE_CHECK_INSTANCE_CAST \
        ((obj), LDM_TYPE_DISK_GROUP, LDMDiskGroup))
#define LDM_DISK_GROUP_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST \
        ((klass), LDM_TYPE_DISK_GROUP, LDMDiskGroupClass))
#define LDM_IS_DISK_GROUP(obj)         (G_TYPE_CHECK_INSTANCE_TYPE \
        ((obj), LDM_TYPE_DISK_GROUP))
#define LDM_IS_DISK_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE \
        ((klass), LDM_TYPE_DISK_GROUP))
#define LDM_DISK_GROUP_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS \
        ((obj), LDM_TYPE_DISK_GROUP, LDMDiskGroupClass))

typedef struct _LDMDiskGroupPrivate LDMDiskGroupPrivate;

typedef struct _LDMDiskGroup LDMDiskGroup;
struct _LDMDiskGroup
{
    GObject parent;
    LDMDiskGroupPrivate *priv;
};

typedef struct
{
    GObjectClass parent_class;
} LDMDiskGroupClass;

/* LDMVolumeType */

typedef enum {
    LDM_VOLUME_TYPE_SIMPLE,
    LDM_VOLUME_TYPE_SPANNED,
    LDM_VOLUME_TYPE_STRIPED,
    LDM_VOLUME_TYPE_MIRRORED,
    LDM_VOLUME_TYPE_RAID5
} LDMVolumeType;

#define LDM_TYPE_VOLUME_TYPE (ldm_volume_type_get_type())

GType ldm_volume_type_get_type(void);

/* LDMVolume */

#define LDM_TYPE_VOLUME            (ldm_volume_get_type())
#define LDM_VOLUME(obj)            (G_TYPE_CHECK_INSTANCE_CAST \
        ((obj), LDM_TYPE_VOLUME, LDMVolume))
#define LDM_VOLUME_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST \
        ((klass), LDM_TYPE_VOLUME, LDMVolumeClass))
#define LDM_IS_VOLUME(obj)         (G_TYPE_CHECK_INSTANCE_TYPE \
        ((obj), LDM_TYPE_VOLUME))
#define LDM_IS_VOLUME_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE \
        ((klass), LDM_TYPE_VOLUME))
#define LDM_VOLUME_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS \
        ((obj), LDM_TYPE_VOLUME, LDMVolumeClass))

typedef struct _LDMVolumePrivate LDMVolumePrivate;

typedef struct _LDMVolume LDMVolume;
struct _LDMVolume
{
    GObject parent;
    LDMVolumePrivate *priv;
};

typedef struct
{
    GObjectClass parent_class;
} LDMVolumeClass;

/* LDMPartition */

#define LDM_TYPE_PARTITION            (ldm_partition_get_type())
#define LDM_PARTITION(obj)            (G_TYPE_CHECK_INSTANCE_CAST \
        ((obj), LDM_TYPE_PARTITION, LDMPartition))
#define LDM_PARTITION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST \
        ((klass), LDM_TYPE_PARTITION, LDMPartitionClass))
#define LDM_IS_PARTITION(obj)         (G_TYPE_CHECK_INSTANCE_TYPE \
        ((obj), LDM_TYPE_PARTITION))
#define LDM_IS_PARTITION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE \
        ((klass), LDM_TYPE_PARTITION))
#define LDM_PARTITION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS \
        ((obj), LDM_TYPE_PARTITION, LDMPartitionClass))

typedef struct _LDMPartitionPrivate LDMPartitionPrivate;

typedef struct _LDMPartition LDMPartition;
struct _LDMPartition
{
    GObject parent;
    LDMPartitionPrivate *priv;
};

typedef struct
{
    GObjectClass parent_class;
} LDMPartitionClass;

/* LDMDisk */

#define LDM_TYPE_DISK            (ldm_disk_get_type())
#define LDM_DISK(obj)            (G_TYPE_CHECK_INSTANCE_CAST \
        ((obj), LDM_TYPE_DISK, LDMDisk))
#define LDM_DISK_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST \
        ((klass), LDM_TYPE_DISK, LDMDiskClass))
#define LDM_IS_DISK(obj)         (G_TYPE_CHECK_INSTANCE_TYPE \
        ((obj), LDM_TYPE_DISK))
#define LDM_IS_DISK_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE \
        ((klass), LDM_TYPE_DISK))
#define LDM_DISK_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS \
        ((obj), LDM_TYPE_DISK, LDMDiskClass))

typedef struct _LDMDiskPrivate LDMDiskPrivate;

typedef struct _LDMDisk LDMDisk;
struct _LDMDisk
{
    GObject parent;
    LDMDiskPrivate *priv;
};

typedef struct
{
    GObjectClass parent_class;
} LDMDiskClass;

GType ldm_get_type(void);
GType ldm_disk_group_get_type(void);

LDM *ldm_new();
gboolean ldm_add(LDM *o, const gchar *path, GError **err);
gboolean ldm_add_fd(LDM *o, int fd, guint secsize, const gchar *path,
                    GError **err);

GArray *ldm_get_disk_groups(LDM *o);

GArray *ldm_disk_group_get_volumes(LDMDiskGroup *o);
GArray *ldm_disk_group_get_partitions(LDMDiskGroup *o);
GArray *ldm_disk_group_get_disks(LDMDiskGroup *o);
gchar *ldm_disk_group_get_name(const LDMDiskGroup *o);
gchar *ldm_disk_group_get_guid(const LDMDiskGroup *o);

GArray *ldm_volume_get_partitions(LDMVolume *o);
gchar *ldm_volume_get_name(const LDMVolume *o);
LDMVolumeType ldm_volume_get_voltype(const LDMVolume *o);
guint64 ldm_volume_get_size(const LDMVolume *o);
guint8 ldm_volume_get_part_type(const LDMVolume *o);
gchar *ldm_volume_get_hint(const LDMVolume *o);
guint64 ldm_volume_get_chunk_size(const LDMVolume *o);

GString *ldm_volume_dm_get_name(const LDMVolume *o);
gboolean ldm_volume_dm_create(const LDMVolume *o, GString **created,
                              GError **err);
gboolean ldm_volume_dm_remove(const LDMVolume *o, GString **removed,
                              GError **err);

LDMDisk *ldm_partition_get_disk(LDMPartition *o);
gchar *ldm_partition_get_name(const LDMPartition *o);
guint64 ldm_partition_get_start(const LDMPartition *o);
guint64 ldm_partition_get_size(const LDMPartition *o);

gchar *ldm_disk_get_name(const LDMDisk *o);
gchar *ldm_disk_get_guid(const LDMDisk *o);
gchar *ldm_disk_get_device(const LDMDisk *o);
guint64 ldm_disk_get_data_start(const LDMDisk *o);
guint64 ldm_disk_get_data_size(const LDMDisk *o);
guint64 ldm_disk_get_metadata_start(const LDMDisk *o);
guint64 ldm_disk_get_metadata_size(const LDMDisk *o);

G_END_DECLS

#endif /* LIBLDM_LDM_H__ */
