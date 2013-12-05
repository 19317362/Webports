#!/bin/bash
# Copyright (c) 2011 The Native Client Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

source pkg_info
source ../../build_tools/common.sh

TestStep() {
  Banner "Testing ${PACKAGE_NAME}"
  if [ ${NACL_ARCH} == "pnacl" ]; then
    local pexe=test/yajl_test
    local script=${PACKAGE_DIR}/${NACL_BUILD_SUBDIR}/yajl_test.sh
    TranslateAndWriteSelLdrScript ${pexe} x86-32 ${pexe}.x86-32.nexe ${script}
    (cd ${PACKAGE_DIR}/test && ./run_tests.sh ${script})
    TranslateAndWriteSelLdrScript ${pexe} x86-64 ${pexe}.x86-64.nexe ${script}
    (cd ${PACKAGE_DIR}/test && ./run_tests.sh ${script})
  else
    local script=${PACKAGE_DIR}/${NACL_BUILD_SUBDIR}/yajl_test.sh
    local nexe=test/yajl_test

    WriteSelLdrScript ${script} ${nexe}
    (cd ${PACKAGE_DIR}/test && LogExecute ./run_tests.sh ${script})
  fi
}


ConfigureStep() {
  Banner "Configuring ${PACKAGE_NAME}"
  export PACKAGE_DIR=${NACL_PACKAGES_REPOSITORY}/${PACKAGE_NAME}
  echo "Directory: $(pwd)"

  MakeDir ${PACKAGE_DIR}/${NACL_BUILD_SUBDIR}
  ChangeDir ${PACKAGE_DIR}/${NACL_BUILD_SUBDIR}

  CC="${NACLCC}" CXX="${NACLCXX}" cmake .. \
    -DCMAKE_TOOLCHAIN_FILE=../XCompile-nacl.txt \
    -DBUILD_SHARED=${NACL_GLIBC} \
    -DNACLAR=${NACLAR} \
    -DNACL_CROSS_PREFIX=${NACL_CROSS_PREFIX} \
    -DNACL_SDK_ROOT=${NACL_SDK_ROOT} \
    -DCMAKE_INSTALL_PREFIX=${NACLPORTS_PREFIX}
}


BuildStep() {
  Banner "Build ${PACKAGE_NAME}"
  echo "Directory: $(pwd)"
  make clean
  make all -j${OS_JOBS}
}


PackageInstall
exit 0