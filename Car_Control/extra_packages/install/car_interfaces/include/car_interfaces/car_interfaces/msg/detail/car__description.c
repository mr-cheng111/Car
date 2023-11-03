// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from car_interfaces:msg/Car.idl
// generated code does not contain a copyright notice

#include "car_interfaces/msg/detail/car__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_car_interfaces
const rosidl_type_hash_t *
car_interfaces__msg__Car__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x53, 0xdf, 0xd7, 0x60, 0x0c, 0x5a, 0x52, 0x05,
      0x75, 0x0d, 0x5b, 0xc5, 0x53, 0x26, 0xfb, 0x1a,
      0x50, 0xea, 0x6d, 0xf8, 0x65, 0x35, 0x8d, 0xba,
      0x70, 0x5b, 0x38, 0x76, 0x37, 0xa9, 0x68, 0x17,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char car_interfaces__msg__Car__TYPE_NAME[] = "car_interfaces/msg/Car";

// Define type names, field names, and default values
static char car_interfaces__msg__Car__FIELD_NAME__speed[] = "speed";
static char car_interfaces__msg__Car__FIELD_NAME__w[] = "w";
static char car_interfaces__msg__Car__FIELD_NAME__x[] = "x";
static char car_interfaces__msg__Car__FIELD_NAME__y[] = "y";

static rosidl_runtime_c__type_description__Field car_interfaces__msg__Car__FIELDS[] = {
  {
    {car_interfaces__msg__Car__FIELD_NAME__speed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {car_interfaces__msg__Car__FIELD_NAME__w, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {car_interfaces__msg__Car__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {car_interfaces__msg__Car__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
car_interfaces__msg__Car__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {car_interfaces__msg__Car__TYPE_NAME, 22, 22},
      {car_interfaces__msg__Car__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 speed\n"
  "float32 w\n"
  "float32 x\n"
  "float32 y";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
car_interfaces__msg__Car__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {car_interfaces__msg__Car__TYPE_NAME, 22, 22},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 44, 44},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
car_interfaces__msg__Car__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *car_interfaces__msg__Car__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
