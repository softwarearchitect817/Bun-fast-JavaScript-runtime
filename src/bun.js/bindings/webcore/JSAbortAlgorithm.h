/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#pragma once

#include "AbortAlgorithm.h"
#include "IDLTypes.h"
#include "JSCallbackData.h"
#include <wtf/Forward.h>

namespace WebCore {

class JSAbortAlgorithm final : public AbortAlgorithm {
public:
    static Ref<JSAbortAlgorithm> create(JSC::VM& vm, JSC::JSObject* callback)
    {
        return adoptRef(*new JSAbortAlgorithm(vm, callback));
    }

    ScriptExecutionContext* scriptExecutionContext() const { return ContextDestructionObserver::scriptExecutionContext(); }

    ~JSAbortAlgorithm() final;
    JSCallbackDataStrong* callbackData() { return m_data; }

    // Functions
    CallbackResult<typename IDLUndefined::ImplementationType> handleEvent() override;

private:
    JSAbortAlgorithm(JSC::VM&, JSC::JSObject* callback);

    JSCallbackDataStrong* m_data;
};

JSC::JSValue toJS(AbortAlgorithm&);
inline JSC::JSValue toJS(AbortAlgorithm* impl) { return impl ? toJS(*impl) : JSC::jsNull(); }

} // namespace WebCore