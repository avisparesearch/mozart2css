#ifndef __MODINTVARPROP_H
#define __MODINTVARPROP_H

#include "../mozartcore.hh"
#include <gecode/int.hh>
#include "cstsupport/intsupport.hh"
namespace mozart {

  namespace builtins {

    // Notes:
    // - All the constraints are posted in vm->getCurrentSpace()
    //   TODO: can I assume that the current space is the same space each
    //   variable belongs to?
    class ModIntVarProp: public Module {
    public:
      ModIntVarProp(): Module("IntVarProp") {}

      class Min3: public Builtin<Min3> {
      public:
	Min3(): Builtin("min3") {}

	static void call(VM vm, In x0, In x1, In x2) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm)){
	    Gecode::min(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting min malformed"), x0);
	  }
	}
      };

      class Min2: public Builtin<Min2> {
      public:
	Min2(): Builtin("min2") {}

	static void call(VM vm, In x, In y) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);

	  if(isIntVarArgs(vm,x) and IntVarLike(y).isIntVarLike(vm)){
	    Gecode::min(home,getIntVarArgs(vm,x),IntVarLike(y).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting min malformed"), x);
	  }
	}
      };

      class Max3: public Builtin<Max3> {
      public:
	Max3(): Builtin("max3") {}
    
	static void call(VM vm, In x0, In x1, In x2) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm)){
	    Gecode::max(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting max malformed"), x0);
	  }
	}
      };
  
      class Max2: public Builtin<Max2> {
      public:
	Max2(): Builtin("max2") {}
    
	static void call(VM vm, In x, In y) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(isIntVarArgs(vm,x) and IntVarLike(y).isIntVarLike(vm)){
	    Gecode::max(home,getIntVarArgs(vm,x),IntVarLike(y).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting max malformed"), x);
	  }
	}
      };
  
      class Abs: public Builtin<Abs> {
      public:
	Abs(): Builtin("abs") {}
    
	static void call(VM vm, In x0, In x1) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);

	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm)){
	    Gecode::abs(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting abs malformed"), x0);
	  }
	}
      };
      
      class Mult: public Builtin<Mult> {
      public:
	Mult(): Builtin("mult") {}
	
	static void call(VM vm, In x0, In x1, In x2) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm)){
	    Gecode::mult(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting mult malformed"), x0);
	  }
	}
      };
      
      class Sqr: public Builtin<Sqr> {
      public:
	Sqr(): Builtin("sqr") {}
    
	static void call(VM vm, In x0, In x1) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
     
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm)){
	    Gecode::sqr(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting sqr malformed"), x0);
	  }
	}
      };

      class Sqrt: public Builtin<Sqrt> {
      public:
	Sqrt(): Builtin("sqrt") {}
    
	static void call(VM vm, In x0, In x1) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);

	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm)){
	    Gecode::sqrt(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting sqrt malformed"), x0);
	  }
	}
      };
  
      class Divmod: public Builtin<Divmod> {
      public:
	Divmod(): Builtin("divmod") {}
    
	static void call(VM vm, In x0, In x1, In x2, In x3) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm) and IntVarLike(x3).isIntVarLike(vm)){
	    Gecode::divmod(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm),IntVarLike(x3).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting divmod malformed"), x0);
	  }
	}
      };

      class DivI: public Builtin<DivI> {
      public:
	DivI(): Builtin("divI") {}
    
	static void call(VM vm, In x0, In x1, In x2) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
     
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm)){
	    Gecode::div(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting div malformed"), x0);
	  }
	}
      };

      class ModI: public Builtin<ModI> {
      public:
	ModI(): Builtin("modI") {}
    
	static void call(VM vm, In x0, In x1, In x2) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm) and IntVarLike(x2).isIntVarLike(vm)){
	    Gecode::mod(home,IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm),IntVarLike(x2).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting mod malformed"), x0);
	  }
	}
      };

      class Dom2: public Builtin<Dom2> {
      public:
	Dom2(): Builtin("dom2") {}

	static void call(VM vm, In x, In n) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);

	  if(IntVarLike(x).isIntVarLike(vm) and n.is<SmallInt>()){
	    nativeint num = n.as<SmallInt>().value();
	    Gecode::dom(home,IntVarLike(x).intVar(vm),(int)(num));
	  }else if(isIntVarArgs(vm,x) and n.is<SmallInt>()){
	    nativeint num = n.as<SmallInt>().value();
	    Gecode::dom(home,getIntVarArgs(vm,x),(int)(num));
	  }else if(IntVarLike(x).isIntVarLike(vm) and isIntSet(vm,n)){
	    Gecode::dom(home,IntVarLike(x).intVar(vm),getIntSet(vm,n));
	  }else if(isIntVarArgs(vm,x) and isIntSet(vm,n)){
	    Gecode::dom(home,getIntVarArgs(vm,x),getIntSet(vm,n));
	  }else{
	    raiseTypeError(vm, ("Propagator posting domain malformed"), x);
	  }
	}
      };

      class Dom3: public Builtin<Dom3> {
      public:
	Dom3(): Builtin("dom3") {}

	static void call(VM vm, In x, In n, In m) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x).isIntVarLike(vm) and n.is<SmallInt>() and m.is<SmallInt>()){
	    nativeint min = n.as<SmallInt>().value();
	    nativeint max = m.as<SmallInt>().value();
	    Gecode::dom(home,IntVarLike(x).intVar(vm),(int)(min),(int)(max));
	  }else if(isIntVarArgs(vm,x) and n.is<SmallInt>() and m.is<SmallInt>()){
	    nativeint min = n.as<SmallInt>().value();
	    nativeint max = m.as<SmallInt>().value();
	    Gecode::dom(home,getIntVarArgs(vm,x),(int)(min),(int)(max));
	  }else if(IntVarLike(x).isIntVarLike(vm) and n.is<SmallInt>() and BoolVarLike(m).isBoolVarLike(vm)){
	    nativeint num = n.as<SmallInt>().value();
	    Gecode::dom(home,IntVarLike(x).intVar(vm),(int)(num),BoolVarLike(m).boolVar(vm));
	  }else if(IntVarLike(x).isIntVarLike(vm) and isIntSet(vm,n) and BoolVarLike(m).isBoolVarLike(vm)){
	    Gecode::dom(home,IntVarLike(x).intVar(vm),getIntSet(vm,n),BoolVarLike(m).boolVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting domain malformed"), x);
	  }
	}
      };

      class Dom4: public Builtin<Dom4> {
      public:
	Dom4(): Builtin("dom4") {}

	static void call(VM vm, In x, In n, In m, In b) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x).isIntVarLike(vm) and n.is<SmallInt>() and m.is<SmallInt>() and BoolVarLike(b).isBoolVarLike(vm)){
	    nativeint min = n.as<SmallInt>().value();
	    nativeint max = m.as<SmallInt>().value();
	    Gecode::dom(home,IntVarLike(x).intVar(vm),(int)(min),(int)(max),BoolVarLike(b).boolVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting domain malformed"), x);
	  }
	}
      };
      
      class Count4: public Builtin<Count4> {
      public:
	Count4(): Builtin("count4") {}
	
	static void call(VM vm, In x, In n, In r, In m) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if ( isIntVarArgs(vm,x) and n.is<SmallInt>() and isAtomToRelType(vm,r) and m.is<SmallInt>()){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::count(home,getIntVarArgs(vm,x),(int)(n.as<SmallInt>().value()),rt,(int)(m.as<SmallInt>().value()));}
	  else if (isIntVarArgs(vm,x) and isIntSet(vm,n) and isAtomToRelType(vm,r) and m.is<SmallInt>()){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::count(home,getIntVarArgs(vm,x),getIntSet(vm,n),rt,(int)(m.as<SmallInt>().value()));
	  }
	  else if ( isIntVarArgs(vm,x) and IntVarLike(n).isIntVarLike(vm) and isAtomToRelType(vm,r) and m.is<SmallInt>()){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::count(home,getIntVarArgs(vm,x),IntVarLike(n).intVar(vm),rt,(int)(m.as<SmallInt>().value()));}
	  else if (isIntVarArgs(vm,x) and isIntArgs(vm,n) and isAtomToRelType(vm,r) and m.is<SmallInt>()){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::count(home,getIntVarArgs(vm,x),getIntArgs(vm,n),rt,(int)(m.as<SmallInt>().value()));}
	  else if (isIntVarArgs(vm,x) and n.is<SmallInt>() and isAtomToRelType(vm,r) and IntVarLike(m).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::count(home,getIntVarArgs(vm,x),(int)(n.as<SmallInt>().value()),rt,IntVarLike(m).intVar(vm));}
	  else if (isIntVarArgs(vm,x) and isIntSet(vm,n) and isAtomToRelType(vm,r) and IntVarLike(m).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::count(home,getIntVarArgs(vm,x), getIntSet(vm,n),rt,IntVarLike(m).intVar(vm));}
	  else if (isIntVarArgs(vm,x) and IntVarLike(n).isIntVarLike(vm) and isAtomToRelType(vm,r) and IntVarLike(m).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::count(home,getIntVarArgs(vm,x), IntVarLike(n).intVar(vm),rt,IntVarLike(m).intVar(vm));}
	  else if (isIntVarArgs(vm,x) and isIntArgs(vm,n) and isAtomToRelType(vm,r) and IntVarLike(m).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::count(home,getIntVarArgs(vm,x), getIntArgs(vm,n),rt,IntVarLike(m).intVar(vm));}
	  else {
	    raiseTypeError(vm,("Propagator posting count malformed"), x);}
	}
      };
      
      class Count2: public Builtin<Count2> {
      public:
	Count2(): Builtin("count2") {}
	
	static void call(VM vm, In x, In c) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntVarArgs(vm,x) and isIntVarArgs(vm,c)){
	    Gecode::count(home,getIntVarArgs(vm,x),getIntVarArgs(vm,c));
	  }
	  else if (isIntVarArgs(vm,x) and isIntSetArgs(vm,c)){
	    Gecode::count(home,getIntVarArgs(vm,x),getIntSetArgs(vm,c));}
	  else {
	    raiseTypeError(vm,("Propagator posting count malformed"), x);}
	}
      };
      
      class Rel2: public Builtin<Rel2> {
      public:
	Rel2(): Builtin("rel2") {}
	
	static void call(VM vm, In x, In r) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  
	  if(isIntVarArgs(vm,x) and isAtomToRelType(vm,r)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::rel(home,getIntVarArgs(vm,x),rt);
	  }else{
	    raiseTypeError(vm, ("Propagator posting rel malformed"), x);
	  }
	}
      };
      
      class Rel3: public Builtin<Rel3> {
      public:
	Rel3(): Builtin("rel3") {}

	static void call(VM vm, In x, In r, In y) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x).isIntVarLike(vm) and isAtomToRelType(vm,r) and IntVarLike(y).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::rel(home,IntVarLike(x).intVar(vm),rt,IntVarLike(y).intVar(vm));
	  }else if(isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and IntVarLike(y).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::rel(home,getIntVarArgs(vm,x),rt,IntVarLike(y).intVar(vm));
	  }else if(IntVarLike(x).isIntVarLike(vm) and isAtomToRelType(vm,r) and y.is<SmallInt>()){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    nativeint num = y.as<SmallInt>().value();
	    Gecode::rel(home,IntVarLike(x).intVar(vm),rt,(int)(num));
	  }else if(isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and y.is<SmallInt>()){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    nativeint num = y.as<SmallInt>().value();
	    Gecode::rel(home,getIntVarArgs(vm,x),rt,(int)(num));
	  }else if(isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and isIntVarArgs(vm,y)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::rel(home,getIntVarArgs(vm,x),rt,getIntVarArgs(vm,y));
	  }else{
	    raiseTypeError(vm, ("Propagator posting rel malformed"), x);
	  }
	}
      };
  
      class Rel4: public Builtin<Rel4> {
      public:
	Rel4(): Builtin("rel4") {}

	static void call(VM vm, In x, In r, In y, In b) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(IntVarLike(x).isIntVarLike(vm) and isAtomToRelType(vm,r) and IntVarLike(y).isIntVarLike(vm) and BoolVarLike(b).isBoolVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::rel(home,IntVarLike(x).intVar(vm),rt,IntVarLike(y).intVar(vm),BoolVarLike(b).boolVar(vm));
	  }else if(IntVarLike(x).isIntVarLike(vm) and isAtomToRelType(vm,r) and y.is<SmallInt>() and BoolVarLike(b).isBoolVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    nativeint num = y.as<SmallInt>().value();
	    Gecode::rel(home,IntVarLike(x).intVar(vm),rt,(int)(num),BoolVarLike(b).boolVar(vm));
	  }
	  else{
	    raiseTypeError(vm, ("Propagator posting rel malformed"), x);
	  }
	}
      };

      class Distinct: public Builtin<Distinct> {
      public:
	Distinct(): Builtin("distinct") {}
    
	static void call(VM vm, In x) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(isIntVarArgs(vm,x)){
	    Gecode::distinct(home,getIntVarArgs(vm,x));
	  }else{
	    raiseTypeError(vm, ("Propagator posting distinct malformed"), x);
	  }
	}
      };

      class Distinct2: public Builtin<Distinct2> {
      public:
	Distinct2(): Builtin("distinct2") {}
    
	static void call(VM vm, In v, In x) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
      
	  if(isIntArgs(vm,v) and isIntVarArgs(vm,x)){
	    Gecode::distinct(home,getIntArgs(vm,v),getIntVarArgs(vm,x));
	  }else{
	    raiseTypeError(vm, ("Propagator posting distinct malformed"), x);
	  }
	}
      };
  
      class Linear3: public Builtin<Linear3> {
      public:
	Linear3(): Builtin("linear3") {}
    
	static void call(VM vm, In v, In r, In x) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  if(isIntVarArgs(vm,v) and isAtomToRelType(vm,r) and x.is<SmallInt>()){
	    nativeint val=x.as<SmallInt>().value();
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntVarArgs(vm,v),rt,(int)(val));
	  }else if(isIntVarArgs(vm,v) and isAtomToRelType(vm,r) and IntVarLike(x).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntVarArgs(vm,v),rt,IntVarLike(x).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting linear malformed"), v);
	  }
	}
      };
      
      class Linear4: public Builtin<Linear4> {
      public:
	Linear4(): Builtin("linear4") {}
    
	static void call(VM vm, In v, In r, In x, In c) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  if(isIntVarArgs(vm,v) and isAtomToRelType(vm,r) and x.is<SmallInt>() and BoolVarLike(c).isBoolVarLike(vm)){
	    nativeint val=x.as<SmallInt>().value();
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntVarArgs(vm,v),rt,(int)(val),BoolVarLike(c).boolVar(vm));
	  }else if(isIntVarArgs(vm,v) and isAtomToRelType(vm,r) and IntVarLike(x).isIntVarLike(vm) and BoolVarLike(c).isBoolVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntVarArgs(vm,v),rt,IntVarLike(x).intVar(vm),BoolVarLike(c).boolVar(vm));
	  }else if(isIntArgs(vm,v) and isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and c.is<SmallInt>()){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    nativeint val=c.as<SmallInt>().value();
	    Gecode::linear(home,getIntArgs(vm,v),getIntVarArgs(vm,x),rt,(int)(val));
	  }else if(isIntArgs(vm,v) and isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and IntVarLike(c).isIntVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntArgs(vm,v),getIntVarArgs(vm,x),rt,IntVarLike(c).intVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting linear malformed"), v);
	  }
	}
      };

      class Linear5: public Builtin<Linear5> {
      public:
	Linear5(): Builtin("linear5") {}
    
	static void call(VM vm, In v, In r, In x, In c, In y) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  if(isIntArgs(vm,v) and isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and c.is<SmallInt>() and BoolVarLike(y).isBoolVarLike(vm)){
	    nativeint val=c.as<SmallInt>().value();
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntArgs(vm,v),getIntVarArgs(vm,x),rt,(int)(val),BoolVarLike(y).boolVar(vm));
	  }else if(isIntArgs(vm,v) and isIntVarArgs(vm,x) and isAtomToRelType(vm,r) and IntVarLike(c).isIntVarLike(vm) and BoolVarLike(y).isBoolVarLike(vm)){
	    Gecode::IntRelType rt = atomToRelType(vm,r);
	    Gecode::linear(home,getIntArgs(vm,v),getIntVarArgs(vm,x),rt,IntVarLike(c).intVar(vm),BoolVarLike(y).boolVar(vm));
	  }else{
	    raiseTypeError(vm, ("Propagator posting linear malformed"), v);
	  }
	}
      };

      class Distribute: public Builtin<Distribute> {
      public:
	Distribute(): Builtin("distribute") {}
	static void call(VM vm, In tec, In v) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  //GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  std::cout << "will choose a distributor" << std::endl; 
	}
      };
      
      class Branch: public Builtin<Branch> {
      public:
	Branch(): Builtin("branch") {}
	static void call(VM vm, In x, In bvar, In bval) {
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace(true);
	  Gecode::IntVarBranch bvart = atomToIntVarBranch(vm,bvar); 
	  Gecode::IntValBranch bvalt = atomToIntValBranch(vm,bval);
	  Gecode::branch(home,getIntVarArgs(vm,x),bvart,bvalt); 
	}
      };
      
      class Element3: public Builtin<Element3>{
      public:
	Element3(): Builtin("element3") {}
	
	static void call(VM vm, In n, In x0, In x1){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntSharedArray(vm,n) and IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm)){
	    Gecode::element(home, getIntSharedArray(vm,n), IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm));
	  }
	  else if (isIntSharedArray(vm,n) and IntVarLike(x0).isIntVarLike(vm) and BoolVarLike(x1).isBoolVarLike(vm)){
	    Gecode::element(home, getIntSharedArray(vm,n), IntVarLike(x0).intVar(vm),BoolVarLike(x1).boolVar(vm));
	  }
	  else if (isIntSharedArray(vm,n) and IntVarLike(x0).isIntVarLike(vm) and x1.is<SmallInt>()){
	    nativeint val = x1.as<SmallInt>().value();
	    Gecode::element(home, getIntSharedArray(vm,n), IntVarLike(x0).intVar(vm),(int)(val));
	  }
	  else if (isIntVarArgs(vm,n) and IntVarLike(x0).isIntVarLike(vm) and IntVarLike(x1).isIntVarLike(vm)){
	    Gecode::element(home,getIntVarArgs(vm,n),IntVarLike(x0).intVar(vm),IntVarLike(x1).intVar(vm));
	  }
	  else if (isIntVarArgs(vm,n) and IntVarLike(x0).isIntVarLike(vm) and x1.is<SmallInt>()){
	    nativeint num = x1.as<SmallInt>().value();
	    Gecode::element(home,getIntVarArgs(vm,n),IntVarLike(x0).intVar(vm),(int)(num));
	  }
	  else if (isBoolVarArgs(vm,n) and IntVarLike(x0).isIntVarLike(vm) and BoolVarLike(x1).isBoolVarLike(vm)){
	    Gecode::element(home,getBoolVarArgs(vm,n),IntVarLike(x0).intVar(vm),BoolVarLike(x1).boolVar(vm));
	  }
	  else if (isBoolVarArgs(vm,n) and IntVarLike(x0).isIntVarLike(vm) and x1.is<SmallInt>()){
	    nativeint num = x1.as<SmallInt>().value();
	    Gecode::element(home,getBoolVarArgs(vm,n),IntVarLike(x0).intVar(vm),(int)(num));
	  }
	  else{
	    raiseTypeError(vm, ("Propagator posting element malformed"), n);}
	}
	
      };
      
      class Element6: public Builtin<Element6>{
      public:
	Element6(): Builtin("element6") {}
	
	static void call(VM vm, In a, In x, In w, In y, In h, In z){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntSharedArray(vm,a) and IntVarLike(x).isIntVarLike(vm) and w.is<SmallInt>() and IntVarLike(y).isIntVarLike(vm) and h.is<SmallInt>() and IntVarLike(z).isIntVarLike(vm)){
	    nativeint numw = w.as<SmallInt>().value();
	    nativeint numh = h.as<SmallInt>().value();
	    Gecode::element(home,getIntSharedArray(vm,a),IntVarLike(x).intVar(vm),(int)(numw),IntVarLike(y).intVar(vm),(int)(numh),IntVarLike(z).intVar(vm));
	  }
	  else if( isIntSharedArray(vm,a) and IntVarLike(x).isIntVarLike(vm) and w.is<SmallInt>() and IntVarLike(y).isIntVarLike(vm) and h.is<SmallInt>() and BoolVarLike(z).isBoolVarLike(vm)){
	    nativeint numw = w.as<SmallInt>().value();
	    nativeint numh = h.as<SmallInt>().value();
	    Gecode::element(home,getIntSharedArray(vm,a),IntVarLike(x).intVar(vm),(int)(numw),IntVarLike(y).intVar(vm),(int)(numh),BoolVarLike(z).boolVar(vm));
	    
	  }
	  else if (isIntVarArgs(vm,a) and IntVarLike(x).isIntVarLike(vm) and w.is<SmallInt>() and IntVarLike(y).isIntVarLike(vm) and h.is<SmallInt>() and IntVarLike(z).isIntVarLike(vm)){
	    nativeint numw = w.as<SmallInt>().value();
	    nativeint numh = h.as<SmallInt>().value();
	    Gecode::element(home,getIntVarArgs(vm,a),IntVarLike(x).intVar(vm),(int)(numw),IntVarLike(y).intVar(vm),(int)(numh),IntVarLike(z).intVar(vm));
	  }
	  else if( isBoolVarArgs(vm,a)  and IntVarLike(x).isIntVarLike(vm) and w.is<SmallInt>() and IntVarLike(y).isIntVarLike(vm) and h.is<SmallInt>() and BoolVarLike(z).isBoolVarLike(vm)){
	    nativeint numw = w.as<SmallInt>().value();
	    nativeint numh = h.as<SmallInt>().value();
	    Gecode::element(home,getBoolVarArgs(vm,a),IntVarLike(x).intVar(vm),(int)(numw),IntVarLike(y).intVar(vm),(int)(numh),BoolVarLike(z).boolVar(vm));
	  }
	  else{
	    raiseTypeError(vm, ("Propagator posting element malformed"), a);}
	}
      };
      
      class Member2: public Builtin<Member2>{
      public:
	Member2(): Builtin("member2") {}
	
	static void call(VM vm,In x, In y){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if(isIntVarArgs(vm,x)and IntVarLike(y).isIntVarLike(vm)){
	    Gecode::member(home,getIntVarArgs(vm,x),IntVarLike(y).intVar(vm));
	  }
	  else if(isBoolVarArgs(vm,x)and BoolVarLike(y).isBoolVarLike(vm)){
	    Gecode::member(home,getBoolVarArgs(vm,x),BoolVarLike(y).boolVar(vm));
	  }
	  else{
	    raiseTypeError(vm, ("Propagator posting member malformed"), x);
	  }
	}
      };
      
      class Member3: public Builtin<Member3>{
      public:
	Member3(): Builtin("member3") {}
	
	static void call(VM vm,In x, In y, In b){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if(isIntVarArgs(vm,x)and IntVarLike(y).isIntVarLike(vm) and BoolVarLike(b).isBoolVarLike(vm)){
	    Gecode::member(home,getIntVarArgs(vm,x),IntVarLike(y).intVar(vm),BoolVarLike(b).boolVar(vm));
	  }
	  else if(isBoolVarArgs(vm,x)and BoolVarLike(y).isBoolVarLike(vm) and BoolVarLike(b).isBoolVarLike(vm)){
	    Gecode::member(home,getBoolVarArgs(vm,x),BoolVarLike(y).boolVar(vm),BoolVarLike(b).boolVar(vm));
	  }
	  else{
	    raiseTypeError(vm, ("Propagator posting member malformed"), x);
	  }
	}
      };
      
      class Sorted2: public Builtin<Sorted2>{
      public:
	Sorted2(): Builtin("sorted2") {}
	
	static void call(VM vm, In x, In y){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if ( isIntVarArgs(vm,x) and isIntVarArgs(vm,y)){
	    Gecode::sorted(home,getIntVarArgs(vm,x),getIntVarArgs(vm,y));
	  }
	  else{
	    raiseTypeError(vm, ("Propagator posting sorted malformed"), x);
	  }
	}	
      };
      
      class Sorted3: public Builtin<Sorted3>{
      public:
	Sorted3(): Builtin("sorted3") {}
	
	static void call(VM vm, In x, In y, In z){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if ( isIntVarArgs(vm,x) and isIntVarArgs(vm,y) and isIntVarArgs(vm,z)){
	    Gecode::sorted(home,getIntVarArgs(vm,x),getIntVarArgs(vm,y),getIntVarArgs(vm,z));
	  }
	  else{
	    raiseTypeError(vm, ("Propagator posting sorted malformed"), x);
	  }
	}	
      };
      
      class Binpacking: public Builtin<Binpacking>{
      public:
	Binpacking(): Builtin("binpacking") {}
	
	static void call(VM vm,In l, In b, In s){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if(isIntVarArgs(vm,l)and isIntVarArgs(vm,b) and isIntArgs(vm,s)){
	    Gecode::binpacking(home,getIntVarArgs(vm,l),getIntVarArgs(vm,b),getIntArgs(vm,s));
	  }
	  else{
	    raiseTypeError(vm, ("Propagator posting binpacking malformed"), l);
	  }
	}
      };
      
      class Channel2: public Builtin<Channel2>{
      public:
	Channel2(): Builtin("channel2") {}
	
	static void call(VM vm,In x, In y){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if(isIntVarArgs(vm,x)and isIntVarArgs(vm,y)){
	    std::cout<<"Im channel Sr!"<<std::endl;
	    Gecode::channel(home,getIntVarArgs(vm,x),getIntVarArgs(vm,y));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting channel malformed"), x);
	  }
	}
      };
      
      class Cumulative5: public Builtin<Cumulative5>{
      public:
	Cumulative5(): Builtin("cumulative5") {}
	
	static void call(VM vm,In c, In t, In flex, In fix, In u){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if(c.is<SmallInt>() and isIntVarArgs(vm,flex)and isIntArgs(vm,fix)and isIntArgs(vm,u)){//falta isTaskTypeArgs
	    nativeint val = c.as<SmallInt>().value();
	    Gecode::cumulative(home,(int)(val),getTaskTypeArgs(vm,t),getIntVarArgs(vm,flex),getIntArgs(vm,fix),getIntArgs(vm,u));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting cumulative malformed"), c);
	  }
	}
      };
      
      class Sequence5: public Builtin<Sequence5>{
      public:
	Sequence5(): Builtin("sequence5") {}
	
	static void call(VM vm,In x, In s, In q, In l, In u){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if( isIntVarArgs(vm,x) and isIntSet(vm,s) and q.is<SmallInt>() and l.is<SmallInt>() and u.is<SmallInt>()){
	    nativeint numq = q.as<SmallInt>().value();
	    nativeint numl = l.as<SmallInt>().value();
	    nativeint numu = u.as<SmallInt>().value();
	    Gecode::sequence(home,getIntVarArgs(vm,x),getIntSet(vm,s),(int)(numq),(int)(numl),(int)(numu));
	  }
	  else if (isBoolVarArgs(vm,x) and isIntSet(vm,s) and q.is<SmallInt>() and l.is<SmallInt>() and u.is<SmallInt>()){
	    nativeint numq = q.as<SmallInt>().value();
	    nativeint numl = l.as<SmallInt>().value();
	    nativeint numu = u.as<SmallInt>().value();
	    Gecode::sequence(home,getBoolVarArgs(vm,x),getIntSet(vm,s),(int)(numq),(int)(numl),(int)(numu));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting sequence malformed"), x);
	  }
	}
      };
      
      class Circuit1: public Builtin<Circuit1>{
      public:
	Circuit1(): Builtin("circuit1") {}
	
	static void call(VM vm, In x){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntVarArgs(vm,x)){
	    Gecode::circuit(home,getIntVarArgs(vm,x));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting circuit malformed"), x);
	  }
	}
      };
      
      class Circuit2: public Builtin<Circuit2>{
      public:
	Circuit2(): Builtin("circuit2") {}
	
	static void call(VM vm, In o, In x){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (o.is<SmallInt>() and isIntVarArgs(vm,x)){
	    nativeint offset = o.as<SmallInt>().value();
	    Gecode::circuit(home,(int)(offset),getIntVarArgs(vm,x));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting circuit malformed"), x);
	  }
	}
      };
      
      class Circuit3: public Builtin<Circuit3>{
      public:
	Circuit3(): Builtin("circuit3") {}
	
	static void call(VM vm, In c, In x, In z){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntArgs(vm,c) and isIntVarArgs(vm,x) and IntVarLike(z).isIntVarLike(vm)){
	    Gecode::circuit(home,getIntArgs(vm,c),getIntVarArgs(vm,x),IntVarLike(z).intVar(vm));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting circuit malformed"), x);
	  }
	}
      };

      class Circuit4: public Builtin<Circuit4>{
      public:
	Circuit4(): Builtin("circuit4") {}
	
	static void call(VM vm, In c, In x, In y,In z){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntArgs(vm,c) and isIntVarArgs(vm,x) and isIntVarArgs(vm,y) and IntVarLike(z).isIntVarLike(vm)){
	    Gecode::circuit(home,getIntArgs(vm,c),getIntVarArgs(vm,x),getIntVarArgs(vm,y),IntVarLike(z).intVar(vm));
	  }
	  else if (isIntArgs(vm,c) and x.is<SmallInt>() and isIntVarArgs(vm,y) and IntVarLike(z).isIntVarLike(vm)){
	    nativeint offset = x.as<SmallInt>().value();
	    Gecode::circuit(home,getIntArgs(vm,c),(int)(offset),getIntVarArgs(vm,y),IntVarLike(z).intVar(vm));
	  } 	  
	  else{
	    raiseTypeError(vm,("Propagator posting circuit malformed"), x);
	  }
	}
      };
      
      class Path3: public Builtin<Path3>{
      public:
	Path3(): Builtin("path3") {}
	
	static void call(VM vm, In x, In s, In e){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntVarArgs(vm,x) and IntVarLike(s).isIntVarLike(vm) and IntVarLike(e).isIntVarLike(vm)){
	    Gecode::path(home,getIntVarArgs(vm,x),IntVarLike(s).intVar(vm),IntVarLike(e).intVar(vm));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting path malformed"), x);
	  }
	}
      };
      
      class Path4: public Builtin<Path4>{
      public:
	Path4(): Builtin("path4") {}
	
	static void call(VM vm, In o, In x, In s, In e){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (o.is<SmallInt>() and isIntVarArgs(vm,x) and IntVarLike(s).isIntVarLike(vm) and IntVarLike(e).isIntVarLike(vm)){
	    nativeint offset = o.as<SmallInt>().value();
	    Gecode::path(home,(int)(offset),getIntVarArgs(vm,x),IntVarLike(s).intVar(vm),IntVarLike(e).intVar(vm));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting path malformed"), x);
	  }
	}
      };
      
      class Path5: public Builtin<Path5>{
      public:
      	Path5(): Builtin("path5") {}
	
      	static void call(VM vm, In c, In x, In s, In e, In z){
      	  assert(vm->getCurrentSpace()->hasConstraintSpace());
      	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
      	  if (isIntArgs(vm,c) and isIntVarArgs(vm,x) and IntVarLike(s).isIntVarLike(vm) and IntVarLike(e).isIntVarLike(vm) and IntVarLike(z).isIntVarLike(vm)){
      	    Gecode::path(home,getIntArgs(vm,c),getIntVarArgs(vm,x),IntVarLike(s).intVar(vm),IntVarLike(e).intVar(vm),IntVarLike(z).intVar(vm));
      	  }
      	  else{
      	    raiseTypeError(vm,("Propagator posting path malformed"), x);
      	  }
      	}
      };

      class Path6: public Builtin<Path6>{
      public:
      	Path6(): Builtin("path6") {}
	
      	static void call(VM vm, In c, In x, In s, In y, In e, In z){
      	  assert(vm->getCurrentSpace()->hasConstraintSpace());
      	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
      	  if (isIntArgs(vm,c) and isIntVarArgs(vm,x) and IntVarLike(s).isIntVarLike(vm) and IntVarLike(e).isIntVarLike(vm) and isIntVarArgs(vm,y) and IntVarLike(z).isIntVarLike(vm)){
      	    Gecode::path(home,getIntArgs(vm,c),getIntVarArgs(vm,x),IntVarLike(s).intVar(vm),IntVarLike(e).intVar(vm),getIntVarArgs(vm,y),IntVarLike(z).intVar(vm));
      	  }
      	  else if (isIntArgs(vm,c) and y.is<SmallInt>() and IntVarLike(s).isIntVarLike(vm) and IntVarLike(e).isIntVarLike(vm) and isIntVarArgs(vm,y) and IntVarLike(z).isIntVarLike(vm)){
      	    nativeint offset = y.as<SmallInt>().value();
      	    Gecode::path(home,getIntArgs(vm,c),(int)(offset),getIntVarArgs(vm,x),IntVarLike(s).intVar(vm),IntVarLike(e).intVar(vm),IntVarLike(z).intVar(vm));
      	  }
      	  else{
      	    raiseTypeError(vm,("Propagator posting path malformed"), x);
      	  }
      	}
      };
      
      class Path7: public Builtin<Path7>{
      public:
      	Path7(): Builtin("path7") {}
	
      	static void call(VM vm, In c, In o, In x, In s, In e, In y, In z){
      	  assert(vm->getCurrentSpace()->hasConstraintSpace());
      	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
      	  if (isIntArgs(vm,c) and o.is<SmallInt>() and isIntVarArgs(vm,x) and IntVarLike(s).isIntVarLike(vm) and IntVarLike(e).isIntVarLike(vm) and isIntVarArgs(vm,y) and IntVarLike(z).isIntVarLike(vm)){
	    nativeint offset = o.as<SmallInt>().value();
      	    Gecode::path(home,getIntArgs(vm,c),(int)(offset),getIntVarArgs(vm,x),IntVarLike(s).intVar(vm),IntVarLike(e).intVar(vm),getIntVarArgs(vm,z),IntVarLike(z).intVar(vm));
      	  }
      	  else{
      	    raiseTypeError(vm,("Propagator posting path malformed"), x);
      	  }
      	}
      };
      
      class Nooverlap4: public Builtin<Nooverlap4>{
      public:
	Nooverlap4(): Builtin("nooverlap4"){}

	static void call(VM vm, In x, In w, In y, In h){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
      	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntVarArgs(vm,x) and isIntArgs(vm,w) and isIntVarArgs(vm,y) and isIntArgs(vm,h)){
	    Gecode::nooverlap(home,getIntVarArgs(vm,x),getIntArgs(vm,w),getIntVarArgs(vm,y),getIntArgs(vm,h));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting nooverlap malformed"), x);
	  }
	}
      };

      class Nooverlap5: public Builtin<Nooverlap5>{
      public:
	Nooverlap5(): Builtin("nooverlap5"){}

	static void call(VM vm, In x, In w, In y, In h, In o){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
      	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntVarArgs(vm,x) and isIntArgs(vm,w) and isIntVarArgs(vm,y) and isIntArgs(vm,h) and isBoolVarArgs(vm,o)){
	    Gecode::nooverlap(home,getIntVarArgs(vm,x),getIntArgs(vm,w),getIntVarArgs(vm,y),getIntArgs(vm,h),getBoolVarArgs(vm,o));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting nooverlap malformed"), x);
	  }
	}
      };

      class Nooverlap6: public Builtin<Nooverlap6>{
      public:
	Nooverlap6(): Builtin("nooverlap6"){}

	static void call(VM vm, In x0, In w, In x1, In y0, In h, In y1){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
      	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntVarArgs(vm,x0) and isIntVarArgs(vm,w) and isIntVarArgs(vm,x1) and isIntArgs(vm,y0) and isIntVarArgs(vm,h) and isIntVarArgs(vm,y1)){
	    Gecode::nooverlap(home,getIntVarArgs(vm,x0),getIntVarArgs(vm,w),getIntVarArgs(vm,x1),getIntVarArgs(vm,y0),getIntVarArgs(vm,h),getIntVarArgs(vm,y1));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting nooverlap malformed"), x0);
	  }
	}
      };

      class Nooverlap7: public Builtin<Nooverlap7>{
      public:
	Nooverlap7(): Builtin("nooverlap7"){}

	static void call(VM vm, In x0, In w, In x1, In y0, In h, In y1, In o){
	  assert(vm->getCurrentSpace()->hasConstraintSpace());
      	  GecodeSpace& home = vm->getCurrentSpace()->getCstSpace();
	  if (isIntVarArgs(vm,x0) and isIntVarArgs(vm,w) and isIntVarArgs(vm,x1) and isIntArgs(vm,y0) and isIntVarArgs(vm,h) and isIntVarArgs(vm,y1) and isBoolVarArgs(vm,o)){
	    Gecode::nooverlap(home,getIntVarArgs(vm,x0),getIntVarArgs(vm,w),getIntVarArgs(vm,x1),getIntVarArgs(vm,y0),getIntVarArgs(vm,h),getIntVarArgs(vm,y1),getBoolVarArgs(vm,o));
	  }
	  else{
	    raiseTypeError(vm,("Propagator posting nooverlap malformed"), x0);
	  }
	}
      };

    }; // class ModIntVarProp
  } // namespace builtins
} // namespace mozart
#endif // __MODINTVARPROP_H
