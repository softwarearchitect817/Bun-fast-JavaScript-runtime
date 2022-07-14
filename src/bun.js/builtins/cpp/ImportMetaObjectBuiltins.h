/*
 * Copyright (c) 2015 Igalia
 * Copyright (c) 2015 Igalia S.L.
 * Copyright (c) 2015 Igalia.
 * Copyright (c) 2015, 2016 Canon Inc. All rights reserved.
 * Copyright (c) 2015, 2016, 2017 Canon Inc.
 * Copyright (c) 2016, 2020 Apple Inc. All rights reserved.
 * Copyright (c) 2022 Codeblog Corp. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

// DO NOT EDIT THIS FILE. It is automatically generated from JavaScript files for
// builtins by the script: Source/JavaScriptCore/Scripts/generate-js-builtins.py

#pragma once

#include <JavaScriptCore/BuiltinUtils.h>
#include <JavaScriptCore/Identifier.h>
#include <JavaScriptCore/JSFunction.h>
#include <JavaScriptCore/UnlinkedFunctionExecutable.h>

namespace JSC {
class FunctionExecutable;
}

namespace WebCore {

/* ImportMetaObject */
extern const char* const s_importMetaObjectRequireCode;
extern const int s_importMetaObjectRequireCodeLength;
extern const JSC::ConstructAbility s_importMetaObjectRequireCodeConstructAbility;
extern const JSC::ConstructorKind s_importMetaObjectRequireCodeConstructorKind;
extern const char* const s_importMetaObjectLoadModuleCode;
extern const int s_importMetaObjectLoadModuleCodeLength;
extern const JSC::ConstructAbility s_importMetaObjectLoadModuleCodeConstructAbility;
extern const JSC::ConstructorKind s_importMetaObjectLoadModuleCodeConstructorKind;
extern const char* const s_importMetaObjectRequireModuleCode;
extern const int s_importMetaObjectRequireModuleCodeLength;
extern const JSC::ConstructAbility s_importMetaObjectRequireModuleCodeConstructAbility;
extern const JSC::ConstructorKind s_importMetaObjectRequireModuleCodeConstructorKind;

#define WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_DATA(macro) \
    macro(require, importMetaObjectRequire, 1) \
    macro(loadModule, importMetaObjectLoadModule, 2) \
    macro(requireModule, importMetaObjectRequireModule, 2) \

#define WEBCORE_BUILTIN_IMPORTMETAOBJECT_REQUIRE 1
#define WEBCORE_BUILTIN_IMPORTMETAOBJECT_LOADMODULE 1
#define WEBCORE_BUILTIN_IMPORTMETAOBJECT_REQUIREMODULE 1

#define WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_CODE(macro) \
    macro(importMetaObjectRequireCode, require, ASCIILiteral(), s_importMetaObjectRequireCodeLength) \
    macro(importMetaObjectLoadModuleCode, loadModule, ASCIILiteral(), s_importMetaObjectLoadModuleCodeLength) \
    macro(importMetaObjectRequireModuleCode, requireModule, ASCIILiteral(), s_importMetaObjectRequireModuleCodeLength) \

#define WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_FUNCTION_NAME(macro) \
    macro(loadModule) \
    macro(require) \
    macro(requireModule) \

#define DECLARE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
    JSC::FunctionExecutable* codeName##Generator(JSC::VM&);

WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_CODE(DECLARE_BUILTIN_GENERATOR)
#undef DECLARE_BUILTIN_GENERATOR

class ImportMetaObjectBuiltinsWrapper : private JSC::WeakHandleOwner {
public:
    explicit ImportMetaObjectBuiltinsWrapper(JSC::VM& vm)
        : m_vm(vm)
        WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_FUNCTION_NAME(INITIALIZE_BUILTIN_NAMES)
#define INITIALIZE_BUILTIN_SOURCE_MEMBERS(name, functionName, overriddenName, length) , m_##name##Source(JSC::makeSource(StringImpl::createWithoutCopying(s_##name, length), { }))
        WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_CODE(INITIALIZE_BUILTIN_SOURCE_MEMBERS)
#undef INITIALIZE_BUILTIN_SOURCE_MEMBERS
    {
    }

#define EXPOSE_BUILTIN_EXECUTABLES(name, functionName, overriddenName, length) \
    JSC::UnlinkedFunctionExecutable* name##Executable(); \
    const JSC::SourceCode& name##Source() const { return m_##name##Source; }
    WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_CODE(EXPOSE_BUILTIN_EXECUTABLES)
#undef EXPOSE_BUILTIN_EXECUTABLES

    WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_FUNCTION_NAME(DECLARE_BUILTIN_IDENTIFIER_ACCESSOR)

    void exportNames();

private:
    JSC::VM& m_vm;

    WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_FUNCTION_NAME(DECLARE_BUILTIN_NAMES)

#define DECLARE_BUILTIN_SOURCE_MEMBERS(name, functionName, overriddenName, length) \
    JSC::SourceCode m_##name##Source;\
    JSC::Weak<JSC::UnlinkedFunctionExecutable> m_##name##Executable;
    WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_CODE(DECLARE_BUILTIN_SOURCE_MEMBERS)
#undef DECLARE_BUILTIN_SOURCE_MEMBERS

};

#define DEFINE_BUILTIN_EXECUTABLES(name, functionName, overriddenName, length) \
inline JSC::UnlinkedFunctionExecutable* ImportMetaObjectBuiltinsWrapper::name##Executable() \
{\
    if (!m_##name##Executable) {\
        JSC::Identifier executableName = functionName##PublicName();\
        if (overriddenName)\
            executableName = JSC::Identifier::fromString(m_vm, overriddenName);\
        m_##name##Executable = JSC::Weak<JSC::UnlinkedFunctionExecutable>(JSC::createBuiltinExecutable(m_vm, m_##name##Source, executableName, s_##name##ConstructorKind, s_##name##ConstructAbility), this, &m_##name##Executable);\
    }\
    return m_##name##Executable.get();\
}
WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_CODE(DEFINE_BUILTIN_EXECUTABLES)
#undef DEFINE_BUILTIN_EXECUTABLES

inline void ImportMetaObjectBuiltinsWrapper::exportNames()
{
#define EXPORT_FUNCTION_NAME(name) m_vm.propertyNames->appendExternalName(name##PublicName(), name##PrivateName());
    WEBCORE_FOREACH_IMPORTMETAOBJECT_BUILTIN_FUNCTION_NAME(EXPORT_FUNCTION_NAME)
#undef EXPORT_FUNCTION_NAME
}

} // namespace WebCore
