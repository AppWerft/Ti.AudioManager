/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This is generated, do not edit by hand. **/

#include <jni.h>

#include "Proxy.h"

namespace de {
namespace appwerft {
namespace audiomanager {

class AudiomanagerModule : public titanium::Proxy
{
public:
	explicit AudiomanagerModule();

	static void bindProxy(v8::Local<v8::Object>, v8::Local<v8::Context>);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Isolate*);
	static void dispose(v8::Isolate*);

	static jclass javaClass;

private:
	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;

	// Methods -----------------------------------------------------------
	static void registerMediaButtonEventReceiver(const v8::FunctionCallbackInfo<v8::Value>&);
	static void unregisterMediaButtonEventReceiver(const v8::FunctionCallbackInfo<v8::Value>&);
	static void requestAudioFocus(const v8::FunctionCallbackInfo<v8::Value>&);
	static void abandonAudioFocus(const v8::FunctionCallbackInfo<v8::Value>&);
	static void registerRouteListener(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getDevices(const v8::FunctionCallbackInfo<v8::Value>&);
	static void unregisterRouteListener(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getAudioRoute(const v8::FunctionCallbackInfo<v8::Value>&);

	// Dynamic property accessors ----------------------------------------

};

} // audiomanager
} // appwerft
} // de
