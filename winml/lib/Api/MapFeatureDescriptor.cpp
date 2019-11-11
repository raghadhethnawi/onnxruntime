﻿// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"

#include "MapFeatureDescriptor.h"

namespace winrt::Windows::AI::MachineLearning::implementation {
MapFeatureDescriptor::MapFeatureDescriptor(
    const char* name,
    const char* description,
    bool is_required,
    winml::TensorKind key_kind,
    winml::ILearningModelFeatureDescriptor value_kind) : name_(WinML::Strings::HStringFromUTF8(name)),
                                                         description_(WinML::Strings::HStringFromUTF8(description)),
                                                         is_required_(is_required),
                                                         key_kind_(key_kind),
                                                         value_kind_(value_kind) {
}

MapFeatureDescriptor::MapFeatureDescriptor(
    hstring const& Name,
    hstring const& Description,
    bool IsRequired,
    Windows::AI::MachineLearning::TensorKind const& KeyKind,
    Windows::AI::MachineLearning::ILearningModelFeatureDescriptor const& ValueDescriptor) : 
        name_(Name),
        description_(Description),
        is_required_(IsRequired),
        key_kind_(KeyKind),
        value_kind_(ValueDescriptor) {
}

winml::TensorKind
MapFeatureDescriptor::KeyKind() try {
  return key_kind_;
}
WINML_CATCH_ALL

winml::ILearningModelFeatureDescriptor
MapFeatureDescriptor::ValueDescriptor() try {
  return value_kind_;
}
WINML_CATCH_ALL

hstring
MapFeatureDescriptor::Name() try {
  return name_;
}
WINML_CATCH_ALL

hstring
MapFeatureDescriptor::Description() try {
  return description_;
}
WINML_CATCH_ALL

winml::LearningModelFeatureKind
MapFeatureDescriptor::Kind() try {
  return LearningModelFeatureKind::Map;
}
WINML_CATCH_ALL

bool MapFeatureDescriptor::IsRequired() try {
  return is_required_;
}
WINML_CATCH_ALL

HRESULT
MapFeatureDescriptor::GetName(
    const wchar_t** name,
    uint32_t* cchName) {
  *name = name_.data();
  *cchName = static_cast<uint32_t>(name_.size());
  return S_OK;
}

HRESULT
MapFeatureDescriptor::GetDescription(
    const wchar_t** description,
    uint32_t* cchDescription) {
  *description = description_.data();
  *cchDescription = static_cast<uint32_t>(description_.size());
  return S_OK;
}
}  // namespace winrt::Windows::AI::MachineLearning::implementation
