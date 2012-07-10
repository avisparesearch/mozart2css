// Copyright © 2011, Université catholique de Louvain
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// *  Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// *  Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef __NAMES_H
#define __NAMES_H

#include "mozartcore.hh"

#ifndef MOZART_GENERATOR

namespace mozart {

/////////////
// OptName //
/////////////

#include "OptName-implem.hh"

void Implementation<OptName>::build(SpaceRef& self, VM vm, GR gr, Self from) {
  gr->copySpace(self, from.get().home());
}

OpResult Implementation<OptName>::makeFeature(Self self, VM vm) {
  self.become(vm, GlobalName::build(vm));
  return OpResult::proceed();
}

////////////////
// GlobalName //
////////////////

#include "GlobalName-implem.hh"

Implementation<GlobalName>::Implementation(VM vm, GR gr, Self from):
  WithHome(vm, gr, from->home()) {

  if (gr->kind() == GraphReplicator::grkSpaceCloning)
    _uuid = vm->genUUID();
  else
    _uuid = from->_uuid;
}

int Implementation<GlobalName>::compareFeatures(VM vm, Self right) {
  const UUID& rhsUUID = right->getUUID();

  if (_uuid == rhsUUID)
    return 0;
  else if (_uuid < rhsUUID)
    return -1;
  else
    return 1;
}

}

#endif // MOZART_GENERATOR

#endif // __NAMES_H
