[![](https://jitpack.io/v/synman/libCrashlyticsMonitor.svg)](https://jitpack.io/#synman/libCrashlyticsMonitor)
[![GitHub issues](https://img.shields.io/github/issues/synman/libCrashlyticsMonitor.svg)](https://github.com/synman/libCrashlyticsMonitor/issues)

# LibCrashlyticsMonitor

A very simple JNI / Native hook for integrating projects with CrashlyticsNdk

Example:

        crashlyticsMonitor = new CrashlyticsMonitor();
        crashlyticsMonitor.initialize(DEVICE_ID);
        
        crashlyticsMonitor.setEmailNameAndPicture(emailAddress, displayName, pictureUrl);
