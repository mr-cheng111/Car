// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from wireless_lidar:msg/LidarData.idl
// generated code does not contain a copyright notice

#include "wireless_lidar/msg/detail/lidar_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
const rosidl_type_hash_t *
wireless_lidar__msg__LidarData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x04, 0x40, 0x26, 0x72, 0x52, 0x14, 0x9c, 0x8e,
      0x8b, 0xc9, 0x9e, 0x4e, 0x5d, 0xad, 0xd9, 0xf2,
      0xce, 0x88, 0x59, 0x5c, 0x1f, 0x06, 0x6d, 0x8e,
      0x77, 0x73, 0x51, 0x97, 0x2f, 0xd5, 0x65, 0x7a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "wireless_lidar/msg/detail/point_data__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t wireless_lidar__msg__PointData__EXPECTED_HASH = {1, {
    0x3a, 0xba, 0xba, 0x4d, 0xea, 0x9a, 0x4b, 0xea,
    0x2a, 0x17, 0xa5, 0x10, 0x5e, 0x8a, 0x92, 0xd8,
    0xc7, 0xb0, 0x2e, 0xd3, 0xf7, 0x0e, 0xe7, 0x15,
    0xf2, 0x13, 0x09, 0x14, 0xa9, 0xd6, 0xe4, 0x28,
  }};
#endif

static char wireless_lidar__msg__LidarData__TYPE_NAME[] = "wireless_lidar/msg/LidarData";
static char wireless_lidar__msg__PointData__TYPE_NAME[] = "wireless_lidar/msg/PointData";

// Define type names, field names, and default values
static char wireless_lidar__msg__LidarData__FIELD_NAME__header[] = "header";
static char wireless_lidar__msg__LidarData__FIELD_NAME__pkg_length[] = "pkg_length";
static char wireless_lidar__msg__LidarData__FIELD_NAME__rate[] = "rate";
static char wireless_lidar__msg__LidarData__FIELD_NAME__start_angle[] = "start_angle";
static char wireless_lidar__msg__LidarData__FIELD_NAME__data[] = "data";
static char wireless_lidar__msg__LidarData__FIELD_NAME__stop_angle[] = "stop_angle";
static char wireless_lidar__msg__LidarData__FIELD_NAME__sum_data[] = "sum_data";

static rosidl_runtime_c__type_description__Field wireless_lidar__msg__LidarData__FIELDS[] = {
  {
    {wireless_lidar__msg__LidarData__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {wireless_lidar__msg__LidarData__FIELD_NAME__pkg_length, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {wireless_lidar__msg__LidarData__FIELD_NAME__rate, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {wireless_lidar__msg__LidarData__FIELD_NAME__start_angle, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {wireless_lidar__msg__LidarData__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_ARRAY,
      16,
      0,
      {wireless_lidar__msg__PointData__TYPE_NAME, 28, 28},
    },
    {NULL, 0, 0},
  },
  {
    {wireless_lidar__msg__LidarData__FIELD_NAME__stop_angle, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {wireless_lidar__msg__LidarData__FIELD_NAME__sum_data, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription wireless_lidar__msg__LidarData__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {wireless_lidar__msg__PointData__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
wireless_lidar__msg__LidarData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {wireless_lidar__msg__LidarData__TYPE_NAME, 28, 28},
      {wireless_lidar__msg__LidarData__FIELDS, 7, 7},
    },
    {wireless_lidar__msg__LidarData__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&wireless_lidar__msg__PointData__EXPECTED_HASH, wireless_lidar__msg__PointData__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = wireless_lidar__msg__PointData__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint16 header\n"
  "uint8 pkg_length\n"
  "uint16 rate\n"
  "uint16 start_angle\n"
  "PointData[16] data\n"
  "uint16 stop_angle\n"
  "uint8 sum_data\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
wireless_lidar__msg__LidarData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {wireless_lidar__msg__LidarData__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 123, 123},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
wireless_lidar__msg__LidarData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *wireless_lidar__msg__LidarData__get_individual_type_description_source(NULL),
    sources[1] = *wireless_lidar__msg__PointData__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
