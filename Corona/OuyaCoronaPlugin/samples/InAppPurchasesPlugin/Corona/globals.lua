-- Copyright (C) 2012, 2013 OUYA, Inc.
--
-- Licensed under the Apache License, Version 2.0 (the "License");
-- you may not use this file except in compliance with the License.
-- You may obtain a copy of the License at
--
--    http://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing, software
-- distributed under the License is distributed on an "AS IS" BASIS,
-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the License for the specific language governing permissions and
-- limitations under the License.

-----------------------------------------------------------------------------------------
--
-- globals.lua
--
-----------------------------------------------------------------------------------------

local globals = {}

globals.centerX = 0;

globals.txtHello = nil;
globals.txtStatus = nil;
globals.txtGamerUsername = nil;
globals.txtGamerUUID = nil;
globals.txtInstructions = nil;

globals.btnProducts = nil;
globals.btnPurchase = nil;
globals.btnReceipts = nil;
globals.btnGamerInfo = nil;
globals.btnPause = nil;

globals.selectedProduct = 0;
globals.getProducts = { };
globals.productTextList = { };

globals.getReceipts = { };
globals.receiptTextList = { };

return globals;