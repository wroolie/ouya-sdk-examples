/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "ODK.h"


#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
// For MIPs (and WP8) platform we do not have asm code for stack switching
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL_LOCK
#endif
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef        int(*OuyaPlugin_getAxis_t)(int deviceId, int axis);
typedef       bool(*OuyaPlugin_isPressed_t)(int deviceId, int keyCode);
typedef       bool(*OuyaPlugin_isPressedDown_t)(int deviceId, int keyCode);
typedef       bool(*OuyaPlugin_isPressedUp_t)(int deviceId, int keyCode);
typedef       void(*OuyaPlugin_clearButtonStates_t)();
typedef const char*(*OuyaPlugin_getDeviceName_t)(int playerNum);
typedef       void(*OuyaPlugin_initOuyaPlugin_t)(const char* jsonData, s3eCallback onSuccess, s3eCallback onFailure);
typedef       void(*OuyaPlugin_asyncOuyaRequestGamerInfo_t)(s3eCallback onSuccess, s3eCallback onFailure, s3eCallback onCancel);
typedef       void(*OuyaPlugin_asyncOuyaRequestProducts_t)(const char* productsJson, s3eCallback onSuccess, s3eCallback onFailure, s3eCallback onCancel);
typedef       void(*OuyaPlugin_asyncOuyaRequestPurchase_t)(const char* purchasable, s3eCallback onSuccess, s3eCallback onFailure, s3eCallback onCancel);
typedef       void(*OuyaPlugin_asyncOuyaRequestReceipts_t)(s3eCallback onSuccess, s3eCallback onFailure, s3eCallback onCancel);
typedef        int(*OuyaPlugin_JSONObject_Construct_t)();
typedef       void(*OuyaPlugin_JSONObject_Put_t)(int jsonObject, const char* name, const char* value);
typedef const char*(*OuyaPlugin_JSONObject_ToString_t)(int jsonObject);
typedef        int(*OuyaPlugin_JSONArray_Construct_t)();
typedef       void(*OuyaPlugin_JSONArray_Put_t)(int jsonArray, int index, int jsonObject);
typedef const char*(*OuyaPlugin_JSONArray_ToString_t)(int jsonArray);

/**
 * struct that gets filled in by ODKRegister
 */
typedef struct ODKFuncs
{
    OuyaPlugin_getAxis_t m_OuyaPlugin_getAxis;
    OuyaPlugin_isPressed_t m_OuyaPlugin_isPressed;
    OuyaPlugin_isPressedDown_t m_OuyaPlugin_isPressedDown;
    OuyaPlugin_isPressedUp_t m_OuyaPlugin_isPressedUp;
    OuyaPlugin_clearButtonStates_t m_OuyaPlugin_clearButtonStates;
    OuyaPlugin_getDeviceName_t m_OuyaPlugin_getDeviceName;
    OuyaPlugin_initOuyaPlugin_t m_OuyaPlugin_initOuyaPlugin;
    OuyaPlugin_asyncOuyaRequestGamerInfo_t m_OuyaPlugin_asyncOuyaRequestGamerInfo;
    OuyaPlugin_asyncOuyaRequestProducts_t m_OuyaPlugin_asyncOuyaRequestProducts;
    OuyaPlugin_asyncOuyaRequestPurchase_t m_OuyaPlugin_asyncOuyaRequestPurchase;
    OuyaPlugin_asyncOuyaRequestReceipts_t m_OuyaPlugin_asyncOuyaRequestReceipts;
    OuyaPlugin_JSONObject_Construct_t m_OuyaPlugin_JSONObject_Construct;
    OuyaPlugin_JSONObject_Put_t m_OuyaPlugin_JSONObject_Put;
    OuyaPlugin_JSONObject_ToString_t m_OuyaPlugin_JSONObject_ToString;
    OuyaPlugin_JSONArray_Construct_t m_OuyaPlugin_JSONArray_Construct;
    OuyaPlugin_JSONArray_Put_t m_OuyaPlugin_JSONArray_Put;
    OuyaPlugin_JSONArray_ToString_t m_OuyaPlugin_JSONArray_ToString;
} ODKFuncs;

static ODKFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xb889863, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: ODK");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xb889863, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool ODKAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

int OuyaPlugin_getAxis(int deviceId, int axis)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[0] func: OuyaPlugin_getAxis"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_OuyaPlugin_getAxis(deviceId, axis);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool OuyaPlugin_isPressed(int deviceId, int keyCode)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[1] func: OuyaPlugin_isPressed"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_OuyaPlugin_isPressed(deviceId, keyCode);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool OuyaPlugin_isPressedDown(int deviceId, int keyCode)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[2] func: OuyaPlugin_isPressedDown"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_OuyaPlugin_isPressedDown(deviceId, keyCode);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool OuyaPlugin_isPressedUp(int deviceId, int keyCode)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[3] func: OuyaPlugin_isPressedUp"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_OuyaPlugin_isPressedUp(deviceId, keyCode);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void OuyaPlugin_clearButtonStates()
{
    IwTrace(ODK_VERBOSE, ("calling ODK[4] func: OuyaPlugin_clearButtonStates"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaPlugin_clearButtonStates();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

const char* OuyaPlugin_getDeviceName(int playerNum)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[5] func: OuyaPlugin_getDeviceName"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    const char* ret = g_Ext.m_OuyaPlugin_getDeviceName(playerNum);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void OuyaPlugin_initOuyaPlugin(const char* jsonData, s3eCallback onSuccess, s3eCallback onFailure)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[6] func: OuyaPlugin_initOuyaPlugin"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaPlugin_initOuyaPlugin(jsonData, onSuccess, onFailure);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void OuyaPlugin_asyncOuyaRequestGamerInfo(s3eCallback onSuccess, s3eCallback onFailure, s3eCallback onCancel)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[7] func: OuyaPlugin_asyncOuyaRequestGamerInfo"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaPlugin_asyncOuyaRequestGamerInfo(onSuccess, onFailure, onCancel);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void OuyaPlugin_asyncOuyaRequestProducts(const char* productsJson, s3eCallback onSuccess, s3eCallback onFailure, s3eCallback onCancel)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[8] func: OuyaPlugin_asyncOuyaRequestProducts"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaPlugin_asyncOuyaRequestProducts(productsJson, onSuccess, onFailure, onCancel);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void OuyaPlugin_asyncOuyaRequestPurchase(const char* purchasable, s3eCallback onSuccess, s3eCallback onFailure, s3eCallback onCancel)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[9] func: OuyaPlugin_asyncOuyaRequestPurchase"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaPlugin_asyncOuyaRequestPurchase(purchasable, onSuccess, onFailure, onCancel);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void OuyaPlugin_asyncOuyaRequestReceipts(s3eCallback onSuccess, s3eCallback onFailure, s3eCallback onCancel)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[10] func: OuyaPlugin_asyncOuyaRequestReceipts"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaPlugin_asyncOuyaRequestReceipts(onSuccess, onFailure, onCancel);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

int OuyaPlugin_JSONObject_Construct()
{
    IwTrace(ODK_VERBOSE, ("calling ODK[11] func: OuyaPlugin_JSONObject_Construct"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_OuyaPlugin_JSONObject_Construct();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void OuyaPlugin_JSONObject_Put(int jsonObject, const char* name, const char* value)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[12] func: OuyaPlugin_JSONObject_Put"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaPlugin_JSONObject_Put(jsonObject, name, value);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

const char* OuyaPlugin_JSONObject_ToString(int jsonObject)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[13] func: OuyaPlugin_JSONObject_ToString"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    const char* ret = g_Ext.m_OuyaPlugin_JSONObject_ToString(jsonObject);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

int OuyaPlugin_JSONArray_Construct()
{
    IwTrace(ODK_VERBOSE, ("calling ODK[14] func: OuyaPlugin_JSONArray_Construct"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_OuyaPlugin_JSONArray_Construct();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void OuyaPlugin_JSONArray_Put(int jsonArray, int index, int jsonObject)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[15] func: OuyaPlugin_JSONArray_Put"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_OuyaPlugin_JSONArray_Put(jsonArray, index, jsonObject);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

const char* OuyaPlugin_JSONArray_ToString(int jsonArray)
{
    IwTrace(ODK_VERBOSE, ("calling ODK[16] func: OuyaPlugin_JSONArray_ToString"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    const char* ret = g_Ext.m_OuyaPlugin_JSONArray_ToString(jsonArray);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}
