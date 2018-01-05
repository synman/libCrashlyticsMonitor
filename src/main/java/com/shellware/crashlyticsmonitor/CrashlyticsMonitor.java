/*
 * Copyright (c) 2017. Shell M. Shrader
 */

package com.shellware.crashlyticsmonitor;

public class CrashlyticsMonitor {

    public void initialize(final String guid) {
        nInitialize(guid, BuildConfig.DEBUG);
    }

    public void setEmailNameAndPicture(final String email, final String name, final String picture) {
        nSetEmailNameAndPicture(email, name, picture);
    }

    public void dispose() {
        nDispose();
    }


    private native void nInitialize(final String guid, final boolean debug);
    private native void nSetEmailNameAndPicture(final String email, final String name, final String picture);
    private native void nDispose();
}
