#!/bin/bash
# Copyright (c) 2014 The Native Client Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

EXTRA_CONFIGURE_ARGS="--with-apr=${NACL_PREFIX}"
EXTRA_CONFIGURE_ARGS+=" --with-expat=${NACL_PREFIX}"
