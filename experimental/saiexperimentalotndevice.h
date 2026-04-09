/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saiexperimentalotndevice.h
 *
 * @brief   This module defines common types and definitions shared by SAI
 *    experimental OTN (Optical Transport Network) modules (attenuator, OA,
 *    OCM, OSC, etc.).
 *
 * @warning This module is a SAI experimental module
 */

#if !defined (__SAIEXPERIMENTALOTNDEVICE_H_)
#define __SAIEXPERIMENTALOTNDEVICE_H_

#include <saitypes.h>

/**
 * @defgroup SAIEXPERIMENTALOTNDEVICE SAI - Experimental: OTN device definitions
 *
 * @{
 */

/**
 * @brief OTN alarm severity
 */
typedef enum _sai_otn_alarm_severity_t
{
    /** OTN alarm severity critical */
    SAI_OTN_ALARM_SEVERITY_CRITICAL,

    /** OTN alarm severity major */
    SAI_OTN_ALARM_SEVERITY_MAJOR,

    /** OTN alarm severity minor */
    SAI_OTN_ALARM_SEVERITY_MINOR,

    /** OTN alarm severity info */
    SAI_OTN_ALARM_SEVERITY_INFO,
} sai_otn_alarm_severity_t;

/**
 * @brief OTN alarm action
 */
typedef enum _sai_otn_alarm_action_t
{
    /** Raise alarm */
    SAI_OTN_ALARM_ACTION_RAISE,

    /** Clear alarm */
    SAI_OTN_ALARM_ACTION_CLEAR,
} sai_otn_alarm_action_t;

/**
 * @brief OTN alarm event data
 */
typedef struct _sai_otn_alarm_event_data_t
{
    /** OTN object id */
    sai_object_id_t object_id;

    /** OTN event name, string */
    sai_u8_list_t event_name;

    /** OTN event timestamp */
    sai_timespec_t timestamp;

    /** OTN event severity */
    sai_otn_alarm_severity_t severity;

    /** OTN event action */
    sai_otn_alarm_action_t action;

    /** OTN event description, string */
    sai_u8_list_t description;

    /** OTN event binary data payload */
    sai_u8_list_t data;

} sai_otn_alarm_event_data_t;

/**
 * @brief OTN alarm event notification
 *
 * @count data[count]
 *
 * @param[in] count Number of notifications
 * @param[in] data Array of OTN alarm events
 */
typedef void (*sai_otn_alarm_event_notification_fn)(
        _In_ uint32_t count,
        _In_ const sai_otn_alarm_event_data_t *data);

/**
 * @brief OTN device attribute IDs
 */
typedef enum _sai_otn_device_attr_t
{
    /**
     * @brief Start of attributes.
     */
    SAI_OTN_DEVICE_ATTR_START,

    /**
     * @brief Admin Mode. if false, the OTN device all the alarm events are suppressed.
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default true
     */
    SAI_OTN_DEVICE_ATTR_ADMIN_STATE = SAI_OTN_DEVICE_ATTR_START,

    /**
     * @brief Alarm event act time in units of milliseconds.
     * Alarm notifications are sent only if the alarm persists beyond the configured delay.
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 2500
     */
    SAI_OTN_DEVICE_ATTR_ALARM_ACT_TIME,

    /**
     * @brief Alarm event deactivate time in units of milliseconds.
     * Clear notifications are sent only if the clear condition persists beyond the configured delay; otherwise, the alarm remains active.
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 10000
     */
    SAI_OTN_DEVICE_ATTR_ALARM_DEACT_TIME,

    /**
     * @brief End of attributes
     */
    SAI_OTN_DEVICE_ATTR_END,

    /** Custom range base value */
    SAI_OTN_DEVICE_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OTN_DEVICE_ATTR_CUSTOM_RANGE_END

} sai_otn_device_attr_t;

/**
 * @brief Create OTN device.
 *
 * Allocates and initializes an OTN device.
 *
 * @param[out] otn_device_id OTN device id
 * @param[in] switch_id Switch id on which the OTN device exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_otn_device_fn)(
        _Out_ sai_object_id_t *otn_device_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OTN device
 *
 * @param[in] otn_device_id OTN device id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_otn_device_fn)(
        _In_ sai_object_id_t otn_device_id);

/**
 * @brief Set OTN device attribute
 *
 * @param[in] otn_device_id OTN device id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_otn_device_attribute_fn)(
        _In_ sai_object_id_t otn_device_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OTN device attribute
 *
 * @param[in] otn_device_id OTN device id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_device_attribute_fn)(
        _In_ sai_object_id_t otn_device_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief OTN device methods table retrieved with sai_api_query()
 */
typedef struct _sai_otn_device_api_t
{
    sai_create_otn_device_fn                create_otn_device;
    sai_remove_otn_device_fn                remove_otn_device;
    sai_set_otn_device_attribute_fn         set_otn_device_attribute;
    sai_get_otn_device_attribute_fn         get_otn_device_attribute;
} sai_otn_device_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALOTNDEVICE_H_ */
