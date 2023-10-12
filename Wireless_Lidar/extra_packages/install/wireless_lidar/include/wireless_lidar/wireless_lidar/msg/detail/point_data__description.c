// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from wireless_lidar:msg/PointData.idl
// generated code does not contain a copyright notice

#include "wireless_lidar/msg/detail/point_data__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_wireless_lidar
const rosidl_type_hash_t *
wireless_lidar__msg__PointData__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3a, 0xba, 0xba, 0x4d, 0xea, 0x9a, 0x4b, 0xea,
      0x2a, 0x17, 0xa5, 0x10, 0x5e, 0x8a, 0x92, 0xd8,
      0xc7, 0xb0, 0x2e, 0xd3, 0xf7, 0x0e, 0xe7, 0x15,
      0xf2, 0x13, 0x09, 0x14, 0xa9, 0xd6, 0xe4, 0x28,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char wireless_lidar__msg__PointData__TYPE_NAME[] = "wireless_lidar/msg/PointData";

// Define type names, field names, and default values
static char wireless_lidar__msg__PointData__FIELD_NAME__distance[] = "distance";
static char wireless_lidar__msg__PointData__FIELD_NAME__strength[] = "strength";

static rosidl_runtime_c__type_description__Field wireless_lidar__msg__PointData__FIELDS[] = {
  {
    {wireless_lidar__msg__PointData__FIELD_NAME__distance, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {wireless_lidar__msg__PointData__FIELD_NAME__strength, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
wireless_lidar__msg__PointData__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {wireless_lidar__msg__PointData__TYPE_NAME, 28, 28},
      {wireless_lidar__msg__PointData__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint16 distance\n"
  "uint8 strength";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
wireless_lidar__msg__PointData__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {wireless_lidar__msg__PointData__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 31, 31},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
wireless_lidar__msg__PointData__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *wireless_lidar__msg__PointData__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
