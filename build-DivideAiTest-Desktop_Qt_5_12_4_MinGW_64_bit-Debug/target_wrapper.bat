@echo off
SetLocal EnableDelayedExpansion
(set PATH=C:\ProgramData\Qt\5.12.4\mingw73_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=C:\ProgramData\Qt\5.12.4\mingw73_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=C:\ProgramData\Qt\5.12.4\mingw73_64\plugins
)
%*
EndLocal
