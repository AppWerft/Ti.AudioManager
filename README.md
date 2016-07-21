#Ti.AudioManager

This is a Titanium module for handling audio stuff on Android.


##Constants

The module exposed some constants:

```javascript

STREAM_MUSIC;
STREAM_ALARM;
STREAM_DTMF;

AUDIOFOCUS_GAIN;
AUDIOFOCUS_GAIN_TRANSIENT;
AUDIOFOCUS_GAIN_TRANSIENT_EXCLUSIVE;
AUDIOFOCUS_GAIN_TRANSIENT_MAY_DUCK;

AUDIOFOCUS_REQUEST_GRANTED;

AUDIOROUTE_BLUETOOTH
AUDIOROUTE_LOUDSPEAKER
AUDIOROUTE_HEADSET
AUDIOROUTE_HDMI
AUDIOROUTE_CHROMECAST




```

Details you will find in [Android documentation](https://developer.android.com/reference/android/media/AudioManager.html)


##Dealing with Audio Output Hardware

###Check What Hardware is Being Used
How your app behaves might be affected by which hardware its output is being routed to.

You can query the AudioManager to determine if the audio is currently being routed to the device speaker, wired headset, or attached Bluetooth device as shown in the following snippet:

```javascript
var AudioManager = request("ti.appwerft.audiomanager");
switch (AudioManager.getAudioRoute()) {
    case AudioManager.AUDIOROUTE_BLUETOOTH:
    case AudioManager.AUDIOROUTE_LOUDSPEAKER:
    case AudioManager.AUDIOROUTE_HEADSET:
}
```

###Handle Changes in the Audio Output Hardware

```javascript
var AudioManager = request("ti.appwerft.audiomanager");
AudioManager.registerRouteListener({
    onAction: function(_e) {
        console.log(_e)
    }
});
//// later:
AudioManager.unregisterRouteListener();
```

##Use Hardware Playback Control Keys to Control Your App’s Audio Playback

Media playback buttons such as play, pause, stop, skip, and previous are available on some handsets and many connected or wireless headsets. 
To respond to media button clicks, you need to register a BroadcastReceiver in your manifest that listens for this action broadcast as shown below.
```xml
<receiver android:name=".RemoteControlReceiver">
    <intent-filter>
        <action android:name="android.intent.action.MEDIA_BUTTON" />
    </intent-filter>
</receiver>
```

```javascript
var AudioManager = request("ti.appwerft.audiomanager");
AudioManager.registerMediaButtonEventReceiver({
    onAction: function(_e) {
        console.log(_e)
    }
});
//// later:
AudioManager.unregisterMediaButtonEventReceiver();
```


##requestAudioFocus()

With multiple apps potentially playing audio it is important to think about how they should interact. To avoid every music app playing at the same time, Android uses audio focus to moderate audio playback—only apps that hold the audio focus should play audio.

Before your app starts playing audio it should request—and receive—the audio focus. Likewise, it should know how to listen for a loss of audio focus and respond appropriately when that happens.

```javascript
var AudioManager = request("ti.appwerft.audiomanager");
AudioManager.requestAudioFocus({
    streamtype : AudioManager.STREAM_MUSIC,
    focusType : AudioManager.AUDIOFOCUS_GAIN);
    onChanged : function(e) {
        console.log(e.state);
    }
};
}
```
##abandonAudioFocus()
Once you've finished playback be sure to call abandonAudioFocus().

```javascript
var AudioManager = request("ti.appwerft.audiomanager");
AudioManager.abandonAudioFocus({
    onChanged : function(e) {
        console.log(e.state);
    }
})
```

##getDevices()

Get all details about all audio devices.