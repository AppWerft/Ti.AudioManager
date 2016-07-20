#Ti.Audiofocus

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
```

Details you will find in [Android documentation](https://developer.android.com/reference/android/media/AudioManager.html)


##requestAudioFocus()

With multiple apps potentially playing audio it's important to think about how they should interact. To avoid every music app playing at the same time, Android uses audio focus to moderate audio playback—only apps that hold the audio focus should play audio.

Before your app starts playing audio it should request—and receive—the audio focus. Likewise, it should know how to listen for a loss of audio focus and respond appropriately when that happens.

```java
var AudioManager = request("ti.appwerft.audiofocus");
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

```java
var AudioManager = request("ti.appwerft.audiofocus");
AudioManager.abandonAudioFocus({
    onChanged : function(e) {
        console.log(e.state);
    }
})
```