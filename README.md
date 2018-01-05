[![](https://jitpack.io/v/synman/libCrashlyticsMonitor.svg)](https://jitpack.io/#synman/libCrashlyticsMonitor)
[![GitHub issues](https://img.shields.io/github/issues/synman/libCrashlyticsMonitor.svg)](https://github.com/synman/libCrashlyticsMonitor/issues)

# LibCrashlyticsMonitor

A very simple JNI / Native hook for integrating projects with CrashlyticsNdk

Example:

    {
        final ANRWatchDog anrWatchDog = new ANRWatchDog(2000);

        anrWatchDog.setTries(3);
        anrWatchDog.setANRListener(new CrashListener());
        anrWatchDog.setReportMainThreadOnly();
    }
    
    private class CrashListener implements ANRWatchDog.ANRListener {
        @Override
        public void onAppNotResponding(ANRError error) {
            if (ARPro3Application.DEBUG) Debug.stopMethodTracing();

            if (piloting) {
                // emergency kill service
                final Intent intent = new Intent(DroneDataService.ACTION_EMERGENCY);
                intent.setPackage(getPackageName());
                startService(intent);

                Log.w(CLASS_NAME, "killing ARDeviceController session due to ANR - try count=" + anrWatchDog.getTriedCount());
                anrTrace.incrementCounter("piloting_freeze");
            } else {
                Log.w(CLASS_NAME, "device appears to be janking - try count=" + anrWatchDog.getTriedCount());
                anrTrace.incrementCounter("general_freeze");
            }
        }

        @Override
        public void onANRWatchDogGivingUp() {
            Log.w(CLASS_NAME, "ANR WatchDog has given up");

            Answers.getInstance().logCustom(new CustomEvent("ANR Watch Dog Shutdown")
                    .putCustomAttribute("SDK", String.valueOf(Build.VERSION.SDK_INT))
                    .putCustomAttribute("Manufacturer", Build.MANUFACTURER)
                    .putCustomAttribute("Model", Build.MODEL)
                    .putCustomAttribute("Release", Build.VERSION.RELEASE)
                    .putCustomAttribute("Codename", Build.VERSION.CODENAME)
                    .putCustomAttribute("Board", Build.BOARD)
                    .putCustomAttribute("Display Name", Build.DISPLAY));

            anrTrace.stop();

            throw new RuntimeException("ANR Watchdog Gave Up");
        }
    }
