/**
 * Copyright (c) 20XX Microsoft Open Technologies, Inc.
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
 * @file    saiexperimentalotnoa.h
 * @brief   This module defines the OA for the SAI
 */

#if !defined (__SAIEXPERIMENTALOTNOA_H_)
#define __SAIEXPERIMENTALOTNOA_H_

#include <saitypes.h>

/**
 * @defgroup SAIOA SAI - OA specific API definitions
 *
 * @{
 */

/** @brief OA type */
typedef enum _sai_otn_oa_type_t
{
    SAI_OTN_OA_TYPE_EDFA,
    SAI_OTN_OA_TYPE_FORWARD_RAMAN,
    SAI_OTN_OA_TYPE_BACKWARD_RAMAN,
    SAI_OTN_OA_TYPE_HYBRID,
} sai_otn_oa_type_t;

/** @brief OA gain range */
typedef enum _sai_otn_oa_gain_range_t
{
    SAI_OTN_OA_GAIN_RANGE_LOW_GAIN_RANGE,
    SAI_OTN_OA_GAIN_RANGE_MID_GAIN_RANGE,
    SAI_OTN_OA_GAIN_RANGE_HIGH_GAIN_RANGE,
    SAI_OTN_OA_GAIN_RANGE_FIXED_GAIN_RANGE,
} sai_otn_oa_gain_range_t;

/** @brief OA amp mode */
typedef enum _sai_otn_oa_amp_mode_t
{
    SAI_OTN_OA_AMP_MODE_CONSTANT_POWER,
    SAI_OTN_OA_AMP_MODE_CONSTANT_GAIN,
    SAI_OTN_OA_AMP_MODE_DYNAMIC_GAIN,
    SAI_OTN_OA_AMP_MODE_DYNAMIC_POWER,
} sai_otn_oa_amp_mode_t;

/** @brief OA fiber type profile */
typedef enum _sai_otn_oa_fiber_type_profile_t
{
    SAI_OTN_OA_FIBER_TYPE_PROFILE_DSF,
    SAI_OTN_OA_FIBER_TYPE_PROFILE_LEAF,
    SAI_OTN_OA_FIBER_TYPE_PROFILE_SSMF,
    SAI_OTN_OA_FIBER_TYPE_PROFILE_TWC,
    SAI_OTN_OA_FIBER_TYPE_PROFILE_TWRS,
} sai_otn_oa_fiber_type_profile_t;

/** @brief OA working state */
typedef enum _sai_otn_oa_working_state_t
{
    SAI_OTN_OA_WORKING_STATE_LOS_A,
    SAI_OTN_OA_WORKING_STATE_LOS_N,
} sai_otn_oa_working_state_t;

/** @brief Operational status */
typedef enum _sai_otn_oa_oper_status_t
{
    SAI_OTN_OA_OPER_STATUS_ACTIVE,
    SAI_OTN_OA_OPER_STATUS_INACTIVE,
    SAI_OTN_OA_OPER_STATUS_DISABLED,
} sai_otn_oa_oper_status_t;

/** @brief Admin state */
typedef enum _sai_otn_oa_admin_state_t
{
    SAI_OTN_OA_ADMIN_STATE_ENABLED,
    SAI_OTN_OA_ADMIN_STATE_DISABLED,
    SAI_OTN_OA_ADMIN_STATE_MAINT,
} sai_otn_oa_admin_state_t;

/**
 * @brief OA attribute IDs
 */
typedef enum _sai_otn_oa_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OTN_OA_ATTR_START,

    /**
     * @brief ID
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_OA_ATTR_ID = SAI_OTN_OA_ATTR_START,

    /**
     * @brief Equipment failure
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_OTN_OA_ATTR_EQUIPMENT_FAILURE,

    /**
     * @brief Equipment mismatch
     *
     * @type bool
     * @flags READ_ONLY
     */
    SAI_OTN_OA_ATTR_EQUIPMENT_MISMATCH,

    /**
     * @brief Admin state
     *
     * @type sai_otn_oa_admin_state_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_OA_ADMIN_STATE_ENABLED
     */
    SAI_OTN_OA_ATTR_ADMIN_STATE,

    /**
     * @brief Operational status
     *
     * @type sai_otn_oa_oper_status_t
     * @flags READ_ONLY
     */
    SAI_OTN_OA_ATTR_OPER_STATUS,

    /**
     * @brief Type
     *
     * @type sai_otn_oa_type_t
     * @flags READ_ONLY
     */
    SAI_OTN_OA_ATTR_TYPE,

    /**
     * @brief Target gain in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 2000
     * @precision 2
     */
    SAI_OTN_OA_ATTR_TARGET_GAIN,

    /**
     * @brief Min gain in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_MIN_GAIN,

    /**
     * @brief Max gain in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_MAX_GAIN,

    /**
     * @brief Target gain tilt in units of 0.01dB
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 0
     * @precision 2
     */
    SAI_OTN_OA_ATTR_TARGET_GAIN_TILT,

    /**
     * @brief Gain range
     *
     * @type sai_otn_oa_gain_range_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_OA_GAIN_RANGE_LOW_GAIN_RANGE
     */
    SAI_OTN_OA_ATTR_GAIN_RANGE,

    /**
     * @brief Amp mode
     *
     * @type sai_otn_oa_amp_mode_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_OA_AMP_MODE_CONSTANT_GAIN
     */
    SAI_OTN_OA_ATTR_AMP_MODE,

    /**
     * @brief Target output power in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 800
     * @precision 2
     */
    SAI_OTN_OA_ATTR_TARGET_OUTPUT_POWER,

    /**
     * @brief Max output power in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 2500
     * @precision 2
     */
    SAI_OTN_OA_ATTR_MAX_OUTPUT_POWER,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_OTN_OA_ATTR_ENABLED,

    /**
     * @brief Fiber type profile
     *
     * @type sai_otn_oa_fiber_type_profile_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_OA_FIBER_TYPE_PROFILE_SSMF
     */
    SAI_OTN_OA_ATTR_FIBER_TYPE_PROFILE,

    /**
     * @brief Working state
     *
     * @type sai_otn_oa_working_state_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_OA_WORKING_STATE_LOS_A
     */
    SAI_OTN_OA_ATTR_WORKING_STATE,

    /**
     * @brief Input LOS threshold in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default -4000
     * @precision 2
     */
    SAI_OTN_OA_ATTR_INPUT_LOS_THRESHOLD,

    /**
     * @brief Input LOS hysteresis in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 300
     * @precision 2
     */
    SAI_OTN_OA_ATTR_INPUT_LOS_HYSTERESIS,

    /**
     * @brief Output LOS threshold in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default -1000
     * @precision 2
     */
    SAI_OTN_OA_ATTR_OUTPUT_LOS_THRESHOLD,

    /**
     * @brief Output LOS hysteresis in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 300
     * @precision 2
     */
    SAI_OTN_OA_ATTR_OUTPUT_LOS_HYSTERESIS,

    /**
     * @brief Gain low threshold in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 500
     * @precision 2
     */
    SAI_OTN_OA_ATTR_GAIN_LOW_THRESHOLD,

    /**
     * @brief Gain low hysteresis in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 50
     * @precision 2
     */
    SAI_OTN_OA_ATTR_GAIN_LOW_HYSTERESIS,

    /**
     * @brief Input low threshold in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default -3700
     * @precision 2
     */
    SAI_OTN_OA_ATTR_INPUT_LOW_THRESHOLD,

    /**
     * @brief Output low threshold in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default -700
     * @precision 2
     */
    SAI_OTN_OA_ATTR_OUTPUT_LOW_THRESHOLD,

    /**
     * @brief LOS ASE delay
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_OTN_OA_ATTR_LOS_ASE_DELAY,

    /**
     * @brief Input offset primary-line rx in units of 0.01dB
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_INPUT_OFFSET_LINEP_RX,

    /**
     * @brief Output offset primary-line tx in units of 0.01dB
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_OUTPUT_OFFSET_LINEP_TX,

    /**
     * @brief Input offset secondary-line rx in units of 0.01dB
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_INPUT_OFFSET_LINES_RX,

    /**
     * @brief Output offset secondary-line tx in units of 0.01dB
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_OUTPUT_OFFSET_LINES_TX,

    /**
     * @brief Enable APR node
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_OTN_OA_ATTR_APR_NODE_ENABLE,

    /**
     * @brief APR node reflection threshold in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags CREATE_AND_SET
     * @default -1700
     * @precision 2
     */
    SAI_OTN_OA_ATTR_APR_NODE_REFLECTION_THRESHOLD,

    /**
     * @brief Enable APR line
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_OTN_OA_ATTR_APR_LINE_ENABLE,

    /**
     * @brief Temperature in units of 0.1 degrees Celsius
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 1
     */
    SAI_OTN_OA_ATTR_TEMPERATURE,

    /**
     * @brief Actual gain in units of 0.01dB
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_ACTUAL_GAIN,

    /**
     * @brief Actual gain tilt in units of 0.01dB
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_ACTUAL_GAIN_TILT,

    /**
     * @brief Input power total in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_INPUT_POWER_TOTAL,

    /**
     * @brief Input power C band in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_INPUT_POWER_C_BAND,

    /**
     * @brief Input power L band in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_INPUT_POWER_L_BAND,

    /**
     * @brief Output power total in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_OUTPUT_POWER_TOTAL,

    /**
     * @brief Output power C band in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_OUTPUT_POWER_C_BAND,

    /**
     * @brief Output power L band in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_OUTPUT_POWER_L_BAND,

    /**
     * @brief Laser bias current in units of 0.01mA
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_LASER_BIAS_CURRENT,

    /**
     * @brief Optical return loss in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_OPTICAL_RETURN_LOSS,

    /**
     * @brief Laser temperature in units of 0.01 degrees Celsius
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_LASER_TEMPERATURE,

    /**
     * @brief Panel input power primary-line rx in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_PANEL_INPUT_POWER_LINEP_RX,

    /**
     * @brief Panel output power primary-line tx in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_PANEL_OUTPUT_POWER_LINEP_TX,

    /**
     * @brief Panel input power secondary-line rx in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_PANEL_INPUT_POWER_LINES_RX,

    /**
     * @brief Panel output power secondary-line tx in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_PANEL_OUTPUT_POWER_LINES_TX,

    /**
     * @brief Laser TEC current in units of 0.01mA
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_LASER_TEC_CURRENT,

    /**
     * @brief Ingress VOA attenuation in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_INGRESS_VOA_ATTEN,

    /**
     * @brief Monitor port output power in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_OA_ATTR_MON_OUTPUT_POWER,

    /**
     * @brief End of attributes
     */
    SAI_OTN_OA_ATTR_END,

    /** Custom range base value */
    SAI_OTN_OA_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OTN_OA_ATTR_CUSTOM_RANGE_END

} sai_otn_oa_attr_t;

/**
 * @brief Create OA.
 *
 * Allocates and initializes a OA.
 *
 * @param[out] otn_oa_id OA id
 * @param[in] switch_id Switch id on which the OA exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_otn_oa_fn)(
        _Out_ sai_object_id_t *otn_oa_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove OA
 *
 * @param[in] otn_oa_id OA id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_otn_oa_fn)(
        _In_ sai_object_id_t otn_oa_id);

/**
 * @brief Set OA attribute
 *
 * @param[in] otn_oa_id OA id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_otn_oa_attribute_fn)(
        _In_ sai_object_id_t otn_oa_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get OA attribute
 *
 * @param[in] otn_oa_id OA id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_oa_attribute_fn)(
        _In_ sai_object_id_t otn_oa_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get OA statistics.
 *
 * @param[in] otn_oa_id OA id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_oa_stats_fn)(
        _In_ sai_object_id_t otn_oa_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ uint64_t *counters);

/**
 * @brief Get OA statistics extended.
 *
 * @param[in] otn_oa_id OA id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_oa_stats_ext_fn)(
        _In_ sai_object_id_t otn_oa_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ uint64_t *counters);

/**
 * @brief Clear OA statistics counters.
 *
 * @param[in] otn_oa_id OA id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_otn_oa_stats_fn)(
        _In_ sai_object_id_t otn_oa_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_otn_oa_api_t
{
    sai_create_otn_oa_fn                create_otn_oa;
    sai_remove_otn_oa_fn                remove_otn_oa;
    sai_set_otn_oa_attribute_fn         set_otn_oa_attribute;
    sai_get_otn_oa_attribute_fn         get_otn_oa_attribute;
    sai_get_otn_oa_stats_fn             get_otn_oa_stats;
    sai_get_otn_oa_stats_ext_fn         get_otn_oa_stats_ext;
    sai_clear_otn_oa_stats_fn           clear_otn_oa_stats;
} sai_otn_oa_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALOTNOA_H_ */