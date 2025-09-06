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
 * @file    saiexperimentalotnattenuator.h
 * @brief   This module defines the attenuator for the SAI
 */

#if !defined (__SAIEXPERIMENTALOTNATTENUATOR_H_)
#define __SAIEXPERIMENTALOTNATTENUATOR_H_

#include <saitypes.h>

/**
 * @defgroup SAIATTENUATOR SAI - Attenuator specific API definitions
 *
 * @{
 */

/** @brief Attenuation mode */
typedef enum _sai_otn_attenuator_attenuation_mode_t
{
    SAI_OTN_ATTENUATOR_ATTENUATION_MODE_CONSTANT_POWER,
    SAI_OTN_ATTENUATOR_ATTENUATION_MODE_CONSTANT_ATTENUATION,
} sai_otn_attenuator_attenuation_mode_t;

/**
 * @brief Attenuator attribute IDs
 */
typedef enum _sai_otn_attenuator_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_OTN_ATTENUATOR_ATTR_START,

    /**
     * @brief ID
     *
     * @type sai_uint32_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_OTN_ATTENUATOR_ATTR_ID = SAI_OTN_ATTENUATOR_ATTR_START,

    /**
     * @brief Attenuation mode
     *
     * @type sai_otn_attenuator_attenuation_mode_t
     * @flags CREATE_AND_SET
     * @default SAI_OTN_ATTENUATOR_ATTENUATION_MODE_CONSTANT_ATTENUATION
     */
    SAI_OTN_ATTENUATOR_ATTR_ATTENUATION_MODE,

    /**
     * @brief Target output power in units of 0.01dBm
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     * @precision 2
     */
    SAI_OTN_ATTENUATOR_ATTR_TARGET_OUTPUT_POWER,

    /**
     * @brief Attenuation in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 500
     * @precision 2
     */
    SAI_OTN_ATTENUATOR_ATTR_ATTENUATION,

    /**
     * @brief Enabled
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default true
     */
    SAI_OTN_ATTENUATOR_ATTR_ENABLED,

    /**
     * @brief Fix attenuation in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_ATTENUATOR_ATTR_FIX_ATTENUATION,

    /**
     * @brief The actual attenuation applied by the attenuator in units of 0.01dB
     *
     * @type sai_uint32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_ATTENUATOR_ATTR_ACTUAL_ATTENUATION,

    /**
     * @brief The total output optical power of this port in units of 0.01dBm
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_ATTENUATOR_ATTR_OUTPUT_POWER_TOTAL,

    /**
     * @brief Optical return loss
     *
     * @type sai_int32_t
     * @flags READ_ONLY
     * @precision 2
     */
    SAI_OTN_ATTENUATOR_ATTR_OPTICAL_RETURN_LOSS,

    /**
     * @brief End of attributes
     */
    SAI_OTN_ATTENUATOR_ATTR_END,

    /** Custom range base value */
    SAI_OTN_ATTENUATOR_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_OTN_ATTENUATOR_ATTR_CUSTOM_RANGE_END

} sai_otn_attenuator_attr_t;

/**
 * @brief Create ATTENUATOR.
 *
 * Allocates and initializes a attenuator.
 *
 * @param[out] otn_attenuator_id Attenuator id
 * @param[in] switch_id Switch id on which the attenuator exists
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_otn_attenuator_fn)(
        _Out_ sai_object_id_t *otn_attenuator_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove attenuator
 *
 * @param[in] otn_attenuator_id Attenuator id
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_otn_attenuator_fn)(
        _In_ sai_object_id_t otn_attenuator_id);

/**
 * @brief Set attenuator attribute
 *
 * @param[in] otn_attenuator_id Attenuator id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_otn_attenuator_attribute_fn)(
        _In_ sai_object_id_t otn_attenuator_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attenuator attribute
 *
 * @param[in] otn_attenuator_id Attenuator id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_attenuator_attribute_fn)(
        _In_ sai_object_id_t otn_attenuator_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Get attenuator statistics.
 *
 * @param[in] otn_attenuator_id Attenuator id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_attenuator_stats_fn)(
        _In_ sai_object_id_t otn_attenuator_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _Out_ uint64_t *counters);

/**
 * @brief Get attenuator statistics extended.
 *
 * @param[in] otn_attenuator_id Attenuator id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[in] mode Statistics mode
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_otn_attenuator_stats_ext_fn)(
        _In_ sai_object_id_t otn_attenuator_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids,
        _In_ sai_stats_mode_t mode,
        _Out_ uint64_t *counters);

/**
 * @brief Clear attenuator statistics counters.
 *
 * @param[in] otn_attenuator_id Attenuator id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_clear_otn_attenuator_stats_fn)(
        _In_ sai_object_id_t otn_attenuator_id,
        _In_ uint32_t number_of_counters,
        _In_ const sai_stat_id_t *counter_ids);

/**
 * @brief Routing interface methods table retrieved with sai_api_query()
 */
typedef struct _sai_otn_attenuator_api_t
{
        sai_create_otn_attenuator_fn                create_otn_attenuator;
        sai_remove_otn_attenuator_fn                remove_otn_attenuator;
        sai_set_otn_attenuator_attribute_fn         set_otn_attenuator_attribute;
        sai_get_otn_attenuator_attribute_fn         get_otn_attenuator_attribute;
        sai_get_otn_attenuator_stats_fn             get_otn_attenuator_stats;
        sai_get_otn_attenuator_stats_ext_fn         get_otn_attenuator_stats_ext;
        sai_clear_otn_attenuator_stats_fn           clear_otn_attenuator_stats;
} sai_otn_attenuator_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALOTNATTENUATOR_H_ */
