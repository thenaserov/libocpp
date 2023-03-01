// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest
#ifndef OCPP_V201_OCPP_TYPES_HPP
#define OCPP_V201_OCPP_TYPES_HPP

#include <string>

#include <boost/optional.hpp>
#include <nlohmann/json.hpp>

#include <ocpp/common/types.hpp>
#include <ocpp/v201/enums.hpp>

namespace ocpp {
namespace v201 {

struct CustomData {
    CiString<255> vendorId;
};
/// \brief Conversion from a given CustomData \p k to a given json object \p j
void to_json(json& j, const CustomData& k);

/// \brief Conversion from a given json object \p j to a given CustomData \p k
void from_json(const json& j, CustomData& k);

// \brief Writes the string representation of the given CustomData \p k to the given output stream \p os
/// \returns an output stream with the CustomData written to
std::ostream& operator<<(std::ostream& os, const CustomData& k);

struct AdditionalInfo {
    CiString<36> additionalIdToken;
    CiString<50> type;
    boost::optional<CustomData> customData;
};
/// \brief Conversion from a given AdditionalInfo \p k to a given json object \p j
void to_json(json& j, const AdditionalInfo& k);

/// \brief Conversion from a given json object \p j to a given AdditionalInfo \p k
void from_json(const json& j, AdditionalInfo& k);

// \brief Writes the string representation of the given AdditionalInfo \p k to the given output stream \p os
/// \returns an output stream with the AdditionalInfo written to
std::ostream& operator<<(std::ostream& os, const AdditionalInfo& k);

struct IdToken {
    CiString<36> idToken;
    IdTokenEnum type;
    boost::optional<CustomData> customData;
    boost::optional<std::vector<AdditionalInfo>> additionalInfo;
};
/// \brief Conversion from a given IdToken \p k to a given json object \p j
void to_json(json& j, const IdToken& k);

/// \brief Conversion from a given json object \p j to a given IdToken \p k
void from_json(const json& j, IdToken& k);

// \brief Writes the string representation of the given IdToken \p k to the given output stream \p os
/// \returns an output stream with the IdToken written to
std::ostream& operator<<(std::ostream& os, const IdToken& k);

struct OCSPRequestData {
    HashAlgorithmEnum hashAlgorithm;
    CiString<128> issuerNameHash;
    CiString<128> issuerKeyHash;
    CiString<40> serialNumber;
    CiString<512> responderURL;
    boost::optional<CustomData> customData;
};
/// \brief Conversion from a given OCSPRequestData \p k to a given json object \p j
void to_json(json& j, const OCSPRequestData& k);

/// \brief Conversion from a given json object \p j to a given OCSPRequestData \p k
void from_json(const json& j, OCSPRequestData& k);

// \brief Writes the string representation of the given OCSPRequestData \p k to the given output stream \p os
/// \returns an output stream with the OCSPRequestData written to
std::ostream& operator<<(std::ostream& os, const OCSPRequestData& k);

struct MessageContent {
    MessageFormatEnum format;
    CiString<512> content;
    boost::optional<CustomData> customData;
    boost::optional<CiString<8>> language;
};
/// \brief Conversion from a given MessageContent \p k to a given json object \p j
void to_json(json& j, const MessageContent& k);

/// \brief Conversion from a given json object \p j to a given MessageContent \p k
void from_json(const json& j, MessageContent& k);

// \brief Writes the string representation of the given MessageContent \p k to the given output stream \p os
/// \returns an output stream with the MessageContent written to
std::ostream& operator<<(std::ostream& os, const MessageContent& k);

struct IdTokenInfo {
    AuthorizationStatusEnum status;
    boost::optional<CustomData> customData;
    boost::optional<ocpp::DateTime> cacheExpiryDateTime;
    boost::optional<int32_t> chargingPriority;
    boost::optional<CiString<8>> language1;
    boost::optional<std::vector<int32_t>> evseId;
    boost::optional<IdToken> groupIdToken;
    boost::optional<CiString<8>> language2;
    boost::optional<MessageContent> personalMessage;
};
/// \brief Conversion from a given IdTokenInfo \p k to a given json object \p j
void to_json(json& j, const IdTokenInfo& k);

/// \brief Conversion from a given json object \p j to a given IdTokenInfo \p k
void from_json(const json& j, IdTokenInfo& k);

// \brief Writes the string representation of the given IdTokenInfo \p k to the given output stream \p os
/// \returns an output stream with the IdTokenInfo written to
std::ostream& operator<<(std::ostream& os, const IdTokenInfo& k);

struct Modem {
    boost::optional<CustomData> customData;
    boost::optional<CiString<20>> iccid;
    boost::optional<CiString<20>> imsi;
};
/// \brief Conversion from a given Modem \p k to a given json object \p j
void to_json(json& j, const Modem& k);

/// \brief Conversion from a given json object \p j to a given Modem \p k
void from_json(const json& j, Modem& k);

// \brief Writes the string representation of the given Modem \p k to the given output stream \p os
/// \returns an output stream with the Modem written to
std::ostream& operator<<(std::ostream& os, const Modem& k);

struct ChargingStation {
    CiString<20> model;
    CiString<50> vendorName;
    boost::optional<CustomData> customData;
    boost::optional<CiString<25>> serialNumber;
    boost::optional<Modem> modem;
    boost::optional<CiString<50>> firmwareVersion;
};
/// \brief Conversion from a given ChargingStation \p k to a given json object \p j
void to_json(json& j, const ChargingStation& k);

/// \brief Conversion from a given json object \p j to a given ChargingStation \p k
void from_json(const json& j, ChargingStation& k);

// \brief Writes the string representation of the given ChargingStation \p k to the given output stream \p os
/// \returns an output stream with the ChargingStation written to
std::ostream& operator<<(std::ostream& os, const ChargingStation& k);

struct StatusInfo {
    CiString<20> reasonCode;
    boost::optional<CustomData> customData;
    boost::optional<CiString<512>> additionalInfo;
};
/// \brief Conversion from a given StatusInfo \p k to a given json object \p j
void to_json(json& j, const StatusInfo& k);

/// \brief Conversion from a given json object \p j to a given StatusInfo \p k
void from_json(const json& j, StatusInfo& k);

// \brief Writes the string representation of the given StatusInfo \p k to the given output stream \p os
/// \returns an output stream with the StatusInfo written to
std::ostream& operator<<(std::ostream& os, const StatusInfo& k);

struct EVSE {
    int32_t id;
    boost::optional<CustomData> customData;
    boost::optional<int32_t> connectorId;
};
/// \brief Conversion from a given EVSE \p k to a given json object \p j
void to_json(json& j, const EVSE& k);

/// \brief Conversion from a given json object \p j to a given EVSE \p k
void from_json(const json& j, EVSE& k);

// \brief Writes the string representation of the given EVSE \p k to the given output stream \p os
/// \returns an output stream with the EVSE written to
std::ostream& operator<<(std::ostream& os, const EVSE& k);

struct ClearChargingProfile {
    boost::optional<CustomData> customData;
    boost::optional<int32_t> evseId;
    boost::optional<ChargingProfilePurposeEnum> chargingProfilePurpose;
    boost::optional<int32_t> stackLevel;
};
/// \brief Conversion from a given ClearChargingProfile \p k to a given json object \p j
void to_json(json& j, const ClearChargingProfile& k);

/// \brief Conversion from a given json object \p j to a given ClearChargingProfile \p k
void from_json(const json& j, ClearChargingProfile& k);

// \brief Writes the string representation of the given ClearChargingProfile \p k to the given output stream \p os
/// \returns an output stream with the ClearChargingProfile written to
std::ostream& operator<<(std::ostream& os, const ClearChargingProfile& k);

struct ClearMonitoringResult {
    ClearMonitoringStatusEnum status;
    int32_t id;
    boost::optional<CustomData> customData;
    boost::optional<StatusInfo> statusInfo;
};
/// \brief Conversion from a given ClearMonitoringResult \p k to a given json object \p j
void to_json(json& j, const ClearMonitoringResult& k);

/// \brief Conversion from a given json object \p j to a given ClearMonitoringResult \p k
void from_json(const json& j, ClearMonitoringResult& k);

// \brief Writes the string representation of the given ClearMonitoringResult \p k to the given output stream \p os
/// \returns an output stream with the ClearMonitoringResult written to
std::ostream& operator<<(std::ostream& os, const ClearMonitoringResult& k);

struct CertificateHashDataType {
    HashAlgorithmEnum hashAlgorithm;
    CiString<128> issuerNameHash;
    CiString<128> issuerKeyHash;
    CiString<40> serialNumber;
    boost::optional<CustomData> customData;
};
/// \brief Conversion from a given CertificateHashDataType \p k to a given json object \p j
void to_json(json& j, const CertificateHashDataType& k);

/// \brief Conversion from a given json object \p j to a given CertificateHashDataType \p k
void from_json(const json& j, CertificateHashDataType& k);

// \brief Writes the string representation of the given CertificateHashDataType \p k to the given output stream \p os
/// \returns an output stream with the CertificateHashDataType written to
std::ostream& operator<<(std::ostream& os, const CertificateHashDataType& k);

struct ChargingProfileCriterion {
    boost::optional<CustomData> customData;
    boost::optional<ChargingProfilePurposeEnum> chargingProfilePurpose;
    boost::optional<int32_t> stackLevel;
    boost::optional<std::vector<int32_t>> chargingProfileId;
    boost::optional<std::vector<ChargingLimitSourceEnum>> chargingLimitSource;
};
/// \brief Conversion from a given ChargingProfileCriterion \p k to a given json object \p j
void to_json(json& j, const ChargingProfileCriterion& k);

/// \brief Conversion from a given json object \p j to a given ChargingProfileCriterion \p k
void from_json(const json& j, ChargingProfileCriterion& k);

// \brief Writes the string representation of the given ChargingProfileCriterion \p k to the given output stream \p os
/// \returns an output stream with the ChargingProfileCriterion written to
std::ostream& operator<<(std::ostream& os, const ChargingProfileCriterion& k);

struct ChargingSchedulePeriod {
    int32_t startPeriod;
    float limit;
    boost::optional<CustomData> customData;
    boost::optional<int32_t> numberPhases;
    boost::optional<int32_t> phaseToUse;
};
/// \brief Conversion from a given ChargingSchedulePeriod \p k to a given json object \p j
void to_json(json& j, const ChargingSchedulePeriod& k);

/// \brief Conversion from a given json object \p j to a given ChargingSchedulePeriod \p k
void from_json(const json& j, ChargingSchedulePeriod& k);

// \brief Writes the string representation of the given ChargingSchedulePeriod \p k to the given output stream \p os
/// \returns an output stream with the ChargingSchedulePeriod written to
std::ostream& operator<<(std::ostream& os, const ChargingSchedulePeriod& k);

struct CompositeSchedule {
    std::vector<ChargingSchedulePeriod> chargingSchedulePeriod;
    int32_t evseId;
    int32_t duration;
    ocpp::DateTime scheduleStart;
    ChargingRateUnitEnum chargingRateUnit;
    boost::optional<CustomData> customData;
};
/// \brief Conversion from a given CompositeSchedule \p k to a given json object \p j
void to_json(json& j, const CompositeSchedule& k);

/// \brief Conversion from a given json object \p j to a given CompositeSchedule \p k
void from_json(const json& j, CompositeSchedule& k);

// \brief Writes the string representation of the given CompositeSchedule \p k to the given output stream \p os
/// \returns an output stream with the CompositeSchedule written to
std::ostream& operator<<(std::ostream& os, const CompositeSchedule& k);

struct CertificateHashDataChain {
    CertificateHashDataType certificateHashData;
    GetCertificateIdUseEnum certificateType;
    boost::optional<CustomData> customData;
    boost::optional<std::vector<CertificateHashDataType>> childCertificateHashData;
};
/// \brief Conversion from a given CertificateHashDataChain \p k to a given json object \p j
void to_json(json& j, const CertificateHashDataChain& k);

/// \brief Conversion from a given json object \p j to a given CertificateHashDataChain \p k
void from_json(const json& j, CertificateHashDataChain& k);

// \brief Writes the string representation of the given CertificateHashDataChain \p k to the given output stream \p os
/// \returns an output stream with the CertificateHashDataChain written to
std::ostream& operator<<(std::ostream& os, const CertificateHashDataChain& k);

struct LogParameters {
    CiString<512> remoteLocation;
    boost::optional<CustomData> customData;
    boost::optional<ocpp::DateTime> oldestTimestamp;
    boost::optional<ocpp::DateTime> latestTimestamp;
};
/// \brief Conversion from a given LogParameters \p k to a given json object \p j
void to_json(json& j, const LogParameters& k);

/// \brief Conversion from a given json object \p j to a given LogParameters \p k
void from_json(const json& j, LogParameters& k);

// \brief Writes the string representation of the given LogParameters \p k to the given output stream \p os
/// \returns an output stream with the LogParameters written to
std::ostream& operator<<(std::ostream& os, const LogParameters& k);

struct Component {
    CiString<50> name;
    boost::optional<CustomData> customData;
    boost::optional<EVSE> evse;
    boost::optional<CiString<50>> instance;
};
/// \brief Conversion from a given Component \p k to a given json object \p j
void to_json(json& j, const Component& k);

/// \brief Conversion from a given json object \p j to a given Component \p k
void from_json(const json& j, Component& k);

// \brief Writes the string representation of the given Component \p k to the given output stream \p os
/// \returns an output stream with the Component written to
std::ostream& operator<<(std::ostream& os, const Component& k);

struct Variable {
    CiString<50> name;
    boost::optional<CustomData> customData;
    boost::optional<CiString<50>> instance;
};
/// \brief Conversion from a given Variable \p k to a given json object \p j
void to_json(json& j, const Variable& k);

/// \brief Conversion from a given json object \p j to a given Variable \p k
void from_json(const json& j, Variable& k);

// \brief Writes the string representation of the given Variable \p k to the given output stream \p os
/// \returns an output stream with the Variable written to
std::ostream& operator<<(std::ostream& os, const Variable& k);

struct ComponentVariable {
    Component component;
    boost::optional<CustomData> customData;
    boost::optional<Variable> variable;
};
/// \brief Conversion from a given ComponentVariable \p k to a given json object \p j
void to_json(json& j, const ComponentVariable& k);

/// \brief Conversion from a given json object \p j to a given ComponentVariable \p k
void from_json(const json& j, ComponentVariable& k);

// \brief Writes the string representation of the given ComponentVariable \p k to the given output stream \p os
/// \returns an output stream with the ComponentVariable written to
std::ostream& operator<<(std::ostream& os, const ComponentVariable& k);

struct GetVariableData {
    Component component;
    Variable variable;
    boost::optional<CustomData> customData;
    boost::optional<AttributeEnum> attributeType;
};
/// \brief Conversion from a given GetVariableData \p k to a given json object \p j
void to_json(json& j, const GetVariableData& k);

/// \brief Conversion from a given json object \p j to a given GetVariableData \p k
void from_json(const json& j, GetVariableData& k);

// \brief Writes the string representation of the given GetVariableData \p k to the given output stream \p os
/// \returns an output stream with the GetVariableData written to
std::ostream& operator<<(std::ostream& os, const GetVariableData& k);

struct GetVariableResult {
    GetVariableStatusEnum attributeStatus;
    Component component;
    Variable variable;
    boost::optional<CustomData> customData;
    boost::optional<StatusInfo> attributeStatusInfo;
    boost::optional<AttributeEnum> attributeType;
    boost::optional<CiString<2500>> attributeValue;
};
/// \brief Conversion from a given GetVariableResult \p k to a given json object \p j
void to_json(json& j, const GetVariableResult& k);

/// \brief Conversion from a given json object \p j to a given GetVariableResult \p k
void from_json(const json& j, GetVariableResult& k);

// \brief Writes the string representation of the given GetVariableResult \p k to the given output stream \p os
/// \returns an output stream with the GetVariableResult written to
std::ostream& operator<<(std::ostream& os, const GetVariableResult& k);

struct SignedMeterValue {
    CiString<2500> signedMeterData;
    CiString<50> signingMethod;
    CiString<50> encodingMethod;
    CiString<2500> publicKey;
    boost::optional<CustomData> customData;
};
/// \brief Conversion from a given SignedMeterValue \p k to a given json object \p j
void to_json(json& j, const SignedMeterValue& k);

/// \brief Conversion from a given json object \p j to a given SignedMeterValue \p k
void from_json(const json& j, SignedMeterValue& k);

// \brief Writes the string representation of the given SignedMeterValue \p k to the given output stream \p os
/// \returns an output stream with the SignedMeterValue written to
std::ostream& operator<<(std::ostream& os, const SignedMeterValue& k);

struct UnitOfMeasure {
    boost::optional<CustomData> customData;
    boost::optional<CiString<20>> unit;
    boost::optional<int32_t> multiplier;
};
/// \brief Conversion from a given UnitOfMeasure \p k to a given json object \p j
void to_json(json& j, const UnitOfMeasure& k);

/// \brief Conversion from a given json object \p j to a given UnitOfMeasure \p k
void from_json(const json& j, UnitOfMeasure& k);

// \brief Writes the string representation of the given UnitOfMeasure \p k to the given output stream \p os
/// \returns an output stream with the UnitOfMeasure written to
std::ostream& operator<<(std::ostream& os, const UnitOfMeasure& k);

struct SampledValue {
    float value;
    boost::optional<CustomData> customData;
    boost::optional<ReadingContextEnum> context;
    boost::optional<MeasurandEnum> measurand;
    boost::optional<PhaseEnum> phase;
    boost::optional<LocationEnum> location;
    boost::optional<SignedMeterValue> signedMeterValue;
    boost::optional<UnitOfMeasure> unitOfMeasure;
};
/// \brief Conversion from a given SampledValue \p k to a given json object \p j
void to_json(json& j, const SampledValue& k);

/// \brief Conversion from a given json object \p j to a given SampledValue \p k
void from_json(const json& j, SampledValue& k);

// \brief Writes the string representation of the given SampledValue \p k to the given output stream \p os
/// \returns an output stream with the SampledValue written to
std::ostream& operator<<(std::ostream& os, const SampledValue& k);

struct MeterValue {
    std::vector<SampledValue> sampledValue;
    ocpp::DateTime timestamp;
    boost::optional<CustomData> customData;
};
/// \brief Conversion from a given MeterValue \p k to a given json object \p j
void to_json(json& j, const MeterValue& k);

/// \brief Conversion from a given json object \p j to a given MeterValue \p k
void from_json(const json& j, MeterValue& k);

// \brief Writes the string representation of the given MeterValue \p k to the given output stream \p os
/// \returns an output stream with the MeterValue written to
std::ostream& operator<<(std::ostream& os, const MeterValue& k);

struct RelativeTimeInterval {
    int32_t start;
    boost::optional<CustomData> customData;
    boost::optional<int32_t> duration;
};
/// \brief Conversion from a given RelativeTimeInterval \p k to a given json object \p j
void to_json(json& j, const RelativeTimeInterval& k);

/// \brief Conversion from a given json object \p j to a given RelativeTimeInterval \p k
void from_json(const json& j, RelativeTimeInterval& k);

// \brief Writes the string representation of the given RelativeTimeInterval \p k to the given output stream \p os
/// \returns an output stream with the RelativeTimeInterval written to
std::ostream& operator<<(std::ostream& os, const RelativeTimeInterval& k);

struct Cost {
    CostKindEnum costKind;
    int32_t amount;
    boost::optional<CustomData> customData;
    boost::optional<int32_t> amountMultiplier;
};
/// \brief Conversion from a given Cost \p k to a given json object \p j
void to_json(json& j, const Cost& k);

/// \brief Conversion from a given json object \p j to a given Cost \p k
void from_json(const json& j, Cost& k);

// \brief Writes the string representation of the given Cost \p k to the given output stream \p os
/// \returns an output stream with the Cost written to
std::ostream& operator<<(std::ostream& os, const Cost& k);

struct ConsumptionCost {
    float startValue;
    std::vector<Cost> cost;
    boost::optional<CustomData> customData;
};
/// \brief Conversion from a given ConsumptionCost \p k to a given json object \p j
void to_json(json& j, const ConsumptionCost& k);

/// \brief Conversion from a given json object \p j to a given ConsumptionCost \p k
void from_json(const json& j, ConsumptionCost& k);

// \brief Writes the string representation of the given ConsumptionCost \p k to the given output stream \p os
/// \returns an output stream with the ConsumptionCost written to
std::ostream& operator<<(std::ostream& os, const ConsumptionCost& k);

struct SalesTariffEntry {
    RelativeTimeInterval relativeTimeInterval;
    boost::optional<CustomData> customData;
    boost::optional<int32_t> ePriceLevel;
    boost::optional<std::vector<ConsumptionCost>> consumptionCost;
};
/// \brief Conversion from a given SalesTariffEntry \p k to a given json object \p j
void to_json(json& j, const SalesTariffEntry& k);

/// \brief Conversion from a given json object \p j to a given SalesTariffEntry \p k
void from_json(const json& j, SalesTariffEntry& k);

// \brief Writes the string representation of the given SalesTariffEntry \p k to the given output stream \p os
/// \returns an output stream with the SalesTariffEntry written to
std::ostream& operator<<(std::ostream& os, const SalesTariffEntry& k);

struct SalesTariff {
    int32_t id;
    std::vector<SalesTariffEntry> salesTariffEntry;
    boost::optional<CustomData> customData;
    boost::optional<CiString<32>> salesTariffDescription;
    boost::optional<int32_t> numEPriceLevels;
};
/// \brief Conversion from a given SalesTariff \p k to a given json object \p j
void to_json(json& j, const SalesTariff& k);

/// \brief Conversion from a given json object \p j to a given SalesTariff \p k
void from_json(const json& j, SalesTariff& k);

// \brief Writes the string representation of the given SalesTariff \p k to the given output stream \p os
/// \returns an output stream with the SalesTariff written to
std::ostream& operator<<(std::ostream& os, const SalesTariff& k);

struct ChargingSchedule {
    int32_t id;
    ChargingRateUnitEnum chargingRateUnit;
    std::vector<ChargingSchedulePeriod> chargingSchedulePeriod;
    boost::optional<CustomData> customData;
    boost::optional<ocpp::DateTime> startSchedule;
    boost::optional<int32_t> duration;
    boost::optional<float> minChargingRate;
    boost::optional<SalesTariff> salesTariff;
};
/// \brief Conversion from a given ChargingSchedule \p k to a given json object \p j
void to_json(json& j, const ChargingSchedule& k);

/// \brief Conversion from a given json object \p j to a given ChargingSchedule \p k
void from_json(const json& j, ChargingSchedule& k);

// \brief Writes the string representation of the given ChargingSchedule \p k to the given output stream \p os
/// \returns an output stream with the ChargingSchedule written to
std::ostream& operator<<(std::ostream& os, const ChargingSchedule& k);

struct ChargingLimit {
    ChargingLimitSourceEnum chargingLimitSource;
    boost::optional<CustomData> customData;
    boost::optional<bool> isGridCritical;
};
/// \brief Conversion from a given ChargingLimit \p k to a given json object \p j
void to_json(json& j, const ChargingLimit& k);

/// \brief Conversion from a given json object \p j to a given ChargingLimit \p k
void from_json(const json& j, ChargingLimit& k);

// \brief Writes the string representation of the given ChargingLimit \p k to the given output stream \p os
/// \returns an output stream with the ChargingLimit written to
std::ostream& operator<<(std::ostream& os, const ChargingLimit& k);

struct MessageInfo {
    int32_t id;
    MessagePriorityEnum priority;
    MessageContent message;
    boost::optional<CustomData> customData;
    boost::optional<Component> display;
    boost::optional<MessageStateEnum> state;
    boost::optional<ocpp::DateTime> startDateTime;
    boost::optional<ocpp::DateTime> endDateTime;
    boost::optional<CiString<36>> transactionId;
};
/// \brief Conversion from a given MessageInfo \p k to a given json object \p j
void to_json(json& j, const MessageInfo& k);

/// \brief Conversion from a given json object \p j to a given MessageInfo \p k
void from_json(const json& j, MessageInfo& k);

// \brief Writes the string representation of the given MessageInfo \p k to the given output stream \p os
/// \returns an output stream with the MessageInfo written to
std::ostream& operator<<(std::ostream& os, const MessageInfo& k);

struct ACChargingParameters {
    int32_t energyAmount;
    int32_t evMinCurrent;
    int32_t evMaxCurrent;
    int32_t evMaxVoltage;
    boost::optional<CustomData> customData;
};
/// \brief Conversion from a given ACChargingParameters \p k to a given json object \p j
void to_json(json& j, const ACChargingParameters& k);

/// \brief Conversion from a given json object \p j to a given ACChargingParameters \p k
void from_json(const json& j, ACChargingParameters& k);

// \brief Writes the string representation of the given ACChargingParameters \p k to the given output stream \p os
/// \returns an output stream with the ACChargingParameters written to
std::ostream& operator<<(std::ostream& os, const ACChargingParameters& k);

struct DCChargingParameters {
    int32_t evMaxCurrent;
    int32_t evMaxVoltage;
    boost::optional<CustomData> customData;
    boost::optional<int32_t> energyAmount;
    boost::optional<int32_t> evMaxPower;
    boost::optional<int32_t> stateOfCharge;
    boost::optional<int32_t> evEnergyCapacity;
    boost::optional<int32_t> fullSoC;
    boost::optional<int32_t> bulkSoC;
};
/// \brief Conversion from a given DCChargingParameters \p k to a given json object \p j
void to_json(json& j, const DCChargingParameters& k);

/// \brief Conversion from a given json object \p j to a given DCChargingParameters \p k
void from_json(const json& j, DCChargingParameters& k);

// \brief Writes the string representation of the given DCChargingParameters \p k to the given output stream \p os
/// \returns an output stream with the DCChargingParameters written to
std::ostream& operator<<(std::ostream& os, const DCChargingParameters& k);

struct ChargingNeeds {
    EnergyTransferModeEnum requestedEnergyTransfer;
    boost::optional<CustomData> customData;
    boost::optional<ACChargingParameters> acChargingParameters;
    boost::optional<DCChargingParameters> dcChargingParameters;
    boost::optional<ocpp::DateTime> departureTime;
};
/// \brief Conversion from a given ChargingNeeds \p k to a given json object \p j
void to_json(json& j, const ChargingNeeds& k);

/// \brief Conversion from a given json object \p j to a given ChargingNeeds \p k
void from_json(const json& j, ChargingNeeds& k);

// \brief Writes the string representation of the given ChargingNeeds \p k to the given output stream \p os
/// \returns an output stream with the ChargingNeeds written to
std::ostream& operator<<(std::ostream& os, const ChargingNeeds& k);

struct EventData {
    int32_t eventId;
    ocpp::DateTime timestamp;
    EventTriggerEnum trigger;
    CiString<2500> actualValue;
    Component component;
    EventNotificationEnum eventNotificationType;
    Variable variable;
    boost::optional<CustomData> customData;
    boost::optional<int32_t> cause;
    boost::optional<CiString<50>> techCode;
    boost::optional<CiString<500>> techInfo;
    boost::optional<bool> cleared;
    boost::optional<CiString<36>> transactionId;
    boost::optional<int32_t> variableMonitoringId;
};
/// \brief Conversion from a given EventData \p k to a given json object \p j
void to_json(json& j, const EventData& k);

/// \brief Conversion from a given json object \p j to a given EventData \p k
void from_json(const json& j, EventData& k);

// \brief Writes the string representation of the given EventData \p k to the given output stream \p os
/// \returns an output stream with the EventData written to
std::ostream& operator<<(std::ostream& os, const EventData& k);

struct VariableMonitoring {
    int32_t id;
    bool transaction;
    float value;
    MonitorEnum type;
    int32_t severity;
    boost::optional<CustomData> customData;
};
/// \brief Conversion from a given VariableMonitoring \p k to a given json object \p j
void to_json(json& j, const VariableMonitoring& k);

/// \brief Conversion from a given json object \p j to a given VariableMonitoring \p k
void from_json(const json& j, VariableMonitoring& k);

// \brief Writes the string representation of the given VariableMonitoring \p k to the given output stream \p os
/// \returns an output stream with the VariableMonitoring written to
std::ostream& operator<<(std::ostream& os, const VariableMonitoring& k);

struct MonitoringData {
    Component component;
    Variable variable;
    std::vector<VariableMonitoring> variableMonitoring;
    boost::optional<CustomData> customData;
};
/// \brief Conversion from a given MonitoringData \p k to a given json object \p j
void to_json(json& j, const MonitoringData& k);

/// \brief Conversion from a given json object \p j to a given MonitoringData \p k
void from_json(const json& j, MonitoringData& k);

// \brief Writes the string representation of the given MonitoringData \p k to the given output stream \p os
/// \returns an output stream with the MonitoringData written to
std::ostream& operator<<(std::ostream& os, const MonitoringData& k);

struct VariableAttribute {
    boost::optional<CustomData> customData;
    boost::optional<AttributeEnum> type;
    boost::optional<CiString<2500>> value;
    boost::optional<MutabilityEnum> mutability;
    boost::optional<bool> persistent;
    boost::optional<bool> constant;
};
/// \brief Conversion from a given VariableAttribute \p k to a given json object \p j
void to_json(json& j, const VariableAttribute& k);

/// \brief Conversion from a given json object \p j to a given VariableAttribute \p k
void from_json(const json& j, VariableAttribute& k);

// \brief Writes the string representation of the given VariableAttribute \p k to the given output stream \p os
/// \returns an output stream with the VariableAttribute written to
std::ostream& operator<<(std::ostream& os, const VariableAttribute& k);

struct VariableCharacteristics {
    DataEnum dataType;
    bool supportsMonitoring;
    boost::optional<CustomData> customData;
    boost::optional<CiString<16>> unit;
    boost::optional<float> minLimit;
    boost::optional<float> maxLimit;
    boost::optional<CiString<1000>> valuesList;
};
/// \brief Conversion from a given VariableCharacteristics \p k to a given json object \p j
void to_json(json& j, const VariableCharacteristics& k);

/// \brief Conversion from a given json object \p j to a given VariableCharacteristics \p k
void from_json(const json& j, VariableCharacteristics& k);

// \brief Writes the string representation of the given VariableCharacteristics \p k to the given output stream \p os
/// \returns an output stream with the VariableCharacteristics written to
std::ostream& operator<<(std::ostream& os, const VariableCharacteristics& k);

struct ReportData {
    Component component;
    Variable variable;
    std::vector<VariableAttribute> variableAttribute;
    boost::optional<CustomData> customData;
    boost::optional<VariableCharacteristics> variableCharacteristics;
};
/// \brief Conversion from a given ReportData \p k to a given json object \p j
void to_json(json& j, const ReportData& k);

/// \brief Conversion from a given json object \p j to a given ReportData \p k
void from_json(const json& j, ReportData& k);

// \brief Writes the string representation of the given ReportData \p k to the given output stream \p os
/// \returns an output stream with the ReportData written to
std::ostream& operator<<(std::ostream& os, const ReportData& k);

struct ChargingProfile {
    int32_t id;
    int32_t stackLevel;
    ChargingProfilePurposeEnum chargingProfilePurpose;
    ChargingProfileKindEnum chargingProfileKind;
    std::vector<ChargingSchedule> chargingSchedule;
    boost::optional<CustomData> customData;
    boost::optional<RecurrencyKindEnum> recurrencyKind;
    boost::optional<ocpp::DateTime> validFrom;
    boost::optional<ocpp::DateTime> validTo;
    boost::optional<CiString<36>> transactionId;
};
/// \brief Conversion from a given ChargingProfile \p k to a given json object \p j
void to_json(json& j, const ChargingProfile& k);

/// \brief Conversion from a given json object \p j to a given ChargingProfile \p k
void from_json(const json& j, ChargingProfile& k);

// \brief Writes the string representation of the given ChargingProfile \p k to the given output stream \p os
/// \returns an output stream with the ChargingProfile written to
std::ostream& operator<<(std::ostream& os, const ChargingProfile& k);

struct AuthorizationData {
    IdToken idToken;
    boost::optional<CustomData> customData;
    boost::optional<IdTokenInfo> idTokenInfo;
};
/// \brief Conversion from a given AuthorizationData \p k to a given json object \p j
void to_json(json& j, const AuthorizationData& k);

/// \brief Conversion from a given json object \p j to a given AuthorizationData \p k
void from_json(const json& j, AuthorizationData& k);

// \brief Writes the string representation of the given AuthorizationData \p k to the given output stream \p os
/// \returns an output stream with the AuthorizationData written to
std::ostream& operator<<(std::ostream& os, const AuthorizationData& k);

struct APN {
    CiString<512> apn;
    APNAuthenticationEnum apnAuthentication;
    boost::optional<CustomData> customData;
    boost::optional<CiString<20>> apnUserName;
    boost::optional<CiString<20>> apnPassword;
    boost::optional<int32_t> simPin;
    boost::optional<CiString<6>> preferredNetwork;
    boost::optional<bool> useOnlyPreferredNetwork;
};
/// \brief Conversion from a given APN \p k to a given json object \p j
void to_json(json& j, const APN& k);

/// \brief Conversion from a given json object \p j to a given APN \p k
void from_json(const json& j, APN& k);

// \brief Writes the string representation of the given APN \p k to the given output stream \p os
/// \returns an output stream with the APN written to
std::ostream& operator<<(std::ostream& os, const APN& k);

struct VPN {
    CiString<512> server;
    CiString<20> user;
    CiString<20> password;
    CiString<255> key;
    VPNEnum type;
    boost::optional<CustomData> customData;
    boost::optional<CiString<20>> group;
};
/// \brief Conversion from a given VPN \p k to a given json object \p j
void to_json(json& j, const VPN& k);

/// \brief Conversion from a given json object \p j to a given VPN \p k
void from_json(const json& j, VPN& k);

// \brief Writes the string representation of the given VPN \p k to the given output stream \p os
/// \returns an output stream with the VPN written to
std::ostream& operator<<(std::ostream& os, const VPN& k);

struct NetworkConnectionProfile {
    OCPPVersionEnum ocppVersion;
    OCPPTransportEnum ocppTransport;
    CiString<512> ocppCsmsUrl;
    int32_t messageTimeout;
    int32_t securityProfile;
    OCPPInterfaceEnum ocppInterface;
    boost::optional<CustomData> customData;
    boost::optional<APN> apn;
    boost::optional<VPN> vpn;
};
/// \brief Conversion from a given NetworkConnectionProfile \p k to a given json object \p j
void to_json(json& j, const NetworkConnectionProfile& k);

/// \brief Conversion from a given json object \p j to a given NetworkConnectionProfile \p k
void from_json(const json& j, NetworkConnectionProfile& k);

// \brief Writes the string representation of the given NetworkConnectionProfile \p k to the given output stream \p os
/// \returns an output stream with the NetworkConnectionProfile written to
std::ostream& operator<<(std::ostream& os, const NetworkConnectionProfile& k);

struct SetMonitoringData {
    float value;
    MonitorEnum type;
    int32_t severity;
    Component component;
    Variable variable;
    boost::optional<CustomData> customData;
    boost::optional<int32_t> id;
    boost::optional<bool> transaction;
};
/// \brief Conversion from a given SetMonitoringData \p k to a given json object \p j
void to_json(json& j, const SetMonitoringData& k);

/// \brief Conversion from a given json object \p j to a given SetMonitoringData \p k
void from_json(const json& j, SetMonitoringData& k);

// \brief Writes the string representation of the given SetMonitoringData \p k to the given output stream \p os
/// \returns an output stream with the SetMonitoringData written to
std::ostream& operator<<(std::ostream& os, const SetMonitoringData& k);

struct SetMonitoringResult {
    SetMonitoringStatusEnum status;
    MonitorEnum type;
    Component component;
    Variable variable;
    int32_t severity;
    boost::optional<CustomData> customData;
    boost::optional<int32_t> id;
    boost::optional<StatusInfo> statusInfo;
};
/// \brief Conversion from a given SetMonitoringResult \p k to a given json object \p j
void to_json(json& j, const SetMonitoringResult& k);

/// \brief Conversion from a given json object \p j to a given SetMonitoringResult \p k
void from_json(const json& j, SetMonitoringResult& k);

// \brief Writes the string representation of the given SetMonitoringResult \p k to the given output stream \p os
/// \returns an output stream with the SetMonitoringResult written to
std::ostream& operator<<(std::ostream& os, const SetMonitoringResult& k);

struct SetVariableData {
    CiString<1000> attributeValue;
    Component component;
    Variable variable;
    boost::optional<CustomData> customData;
    boost::optional<AttributeEnum> attributeType;
};
/// \brief Conversion from a given SetVariableData \p k to a given json object \p j
void to_json(json& j, const SetVariableData& k);

/// \brief Conversion from a given json object \p j to a given SetVariableData \p k
void from_json(const json& j, SetVariableData& k);

// \brief Writes the string representation of the given SetVariableData \p k to the given output stream \p os
/// \returns an output stream with the SetVariableData written to
std::ostream& operator<<(std::ostream& os, const SetVariableData& k);

struct SetVariableResult {
    SetVariableStatusEnum attributeStatus;
    Component component;
    Variable variable;
    boost::optional<CustomData> customData;
    boost::optional<AttributeEnum> attributeType;
    boost::optional<StatusInfo> attributeStatusInfo;
};
/// \brief Conversion from a given SetVariableResult \p k to a given json object \p j
void to_json(json& j, const SetVariableResult& k);

/// \brief Conversion from a given json object \p j to a given SetVariableResult \p k
void from_json(const json& j, SetVariableResult& k);

// \brief Writes the string representation of the given SetVariableResult \p k to the given output stream \p os
/// \returns an output stream with the SetVariableResult written to
std::ostream& operator<<(std::ostream& os, const SetVariableResult& k);

struct Transaction {
    CiString<36> transactionId;
    boost::optional<CustomData> customData;
    boost::optional<ChargingStateEnum> chargingState;
    boost::optional<int32_t> timeSpentCharging;
    boost::optional<ReasonEnum> stoppedReason;
    boost::optional<int32_t> remoteStartId;
};
/// \brief Conversion from a given Transaction \p k to a given json object \p j
void to_json(json& j, const Transaction& k);

/// \brief Conversion from a given json object \p j to a given Transaction \p k
void from_json(const json& j, Transaction& k);

// \brief Writes the string representation of the given Transaction \p k to the given output stream \p os
/// \returns an output stream with the Transaction written to
std::ostream& operator<<(std::ostream& os, const Transaction& k);

struct Firmware {
    CiString<512> location;
    ocpp::DateTime retrieveDateTime;
    boost::optional<CustomData> customData;
    boost::optional<ocpp::DateTime> installDateTime;
    boost::optional<CiString<5500>> signingCertificate;
    boost::optional<CiString<800>> signature;
};
/// \brief Conversion from a given Firmware \p k to a given json object \p j
void to_json(json& j, const Firmware& k);

/// \brief Conversion from a given json object \p j to a given Firmware \p k
void from_json(const json& j, Firmware& k);

// \brief Writes the string representation of the given Firmware \p k to the given output stream \p os
/// \returns an output stream with the Firmware written to
std::ostream& operator<<(std::ostream& os, const Firmware& k);

} // namespace v201
} // namespace ocpp

#endif // OCPP_V201_OCPP_TYPES_HPP