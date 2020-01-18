[![](https://jitpack.io/v/synman/libCrashlyticsMonitor.svg)](https://jitpack.io/#synman/libCrashlyticsMonitor)
[![GitHub issues](https://img.shields.io/github/issues/synman/libCrashlyticsMonitor.svg)](https://github.com/synman/libCrashlyticsMonitor/issues)

# LibCrashlyticsMonitor

**This library is deprecated.**  Please use Firebase Native Crashlytics Reporting from March 2020 onward.  More details can be found here:  https://firebase.google.com/docs/crashlytics/ndk-reports-new-sdk


A very simple JNI / Native hook for integrating projects with CrashlyticsNdk

Example:
```java
        final CrashlysticsMonitor crashlyticsMonitor = new CrashlyticsMonitor();
        crashlyticsMonitor.initialize(DEVICE_ID);
        
        crashlyticsMonitor.setEmailNameAndPicture(emailAddress, displayName, pictureUrl);
```
