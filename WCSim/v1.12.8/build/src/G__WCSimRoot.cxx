// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__WCSimRoot
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "jhfNtuple.h"
#include "WCSimRootEvent.hh"
#include "WCSimRootGeom.hh"
#include "WCSimPmtInfo.hh"
#include "WCSimEnumerations.hh"
#include "WCSimRootOptions.hh"
#include "WCSimRootTools.hh"
#include "TJNuBeamFlux.hh"
#include "TNRooTrackerVtx.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *pairlEstringcOWCSimDarkNoiseOptionsgR_Dictionary();
   static void pairlEstringcOWCSimDarkNoiseOptionsgR_TClassManip(TClass*);
   static void *new_pairlEstringcOWCSimDarkNoiseOptionsgR(void *p = nullptr);
   static void *newArray_pairlEstringcOWCSimDarkNoiseOptionsgR(Long_t size, void *p);
   static void delete_pairlEstringcOWCSimDarkNoiseOptionsgR(void *p);
   static void deleteArray_pairlEstringcOWCSimDarkNoiseOptionsgR(void *p);
   static void destruct_pairlEstringcOWCSimDarkNoiseOptionsgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<string,WCSimDarkNoiseOptions>*)
   {
      pair<string,WCSimDarkNoiseOptions> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<string,WCSimDarkNoiseOptions>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<string,WCSimDarkNoiseOptions>", "string", 187,
                  typeid(pair<string,WCSimDarkNoiseOptions>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &pairlEstringcOWCSimDarkNoiseOptionsgR_Dictionary, isa_proxy, 4,
                  sizeof(pair<string,WCSimDarkNoiseOptions>) );
      instance.SetNew(&new_pairlEstringcOWCSimDarkNoiseOptionsgR);
      instance.SetNewArray(&newArray_pairlEstringcOWCSimDarkNoiseOptionsgR);
      instance.SetDelete(&delete_pairlEstringcOWCSimDarkNoiseOptionsgR);
      instance.SetDeleteArray(&deleteArray_pairlEstringcOWCSimDarkNoiseOptionsgR);
      instance.SetDestructor(&destruct_pairlEstringcOWCSimDarkNoiseOptionsgR);

      instance.AdoptAlternate(::ROOT::AddClassAlternate("pair<string,WCSimDarkNoiseOptions>","pair<std::string,WCSimDarkNoiseOptions>"));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("pair<string,WCSimDarkNoiseOptions>","std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, WCSimDarkNoiseOptions>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const pair<string,WCSimDarkNoiseOptions>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEstringcOWCSimDarkNoiseOptionsgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const pair<string,WCSimDarkNoiseOptions>*>(nullptr))->GetClass();
      pairlEstringcOWCSimDarkNoiseOptionsgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEstringcOWCSimDarkNoiseOptionsgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *WCSimEnumerations_Dictionary();
   static void WCSimEnumerations_TClassManip(TClass*);
   static void *new_WCSimEnumerations(void *p = nullptr);
   static void *newArray_WCSimEnumerations(Long_t size, void *p);
   static void delete_WCSimEnumerations(void *p);
   static void deleteArray_WCSimEnumerations(void *p);
   static void destruct_WCSimEnumerations(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimEnumerations*)
   {
      ::WCSimEnumerations *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::WCSimEnumerations));
      static ::ROOT::TGenericClassInfo 
         instance("WCSimEnumerations", "WCSimEnumerations.hh", 174,
                  typeid(::WCSimEnumerations), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &WCSimEnumerations_Dictionary, isa_proxy, 4,
                  sizeof(::WCSimEnumerations) );
      instance.SetNew(&new_WCSimEnumerations);
      instance.SetNewArray(&newArray_WCSimEnumerations);
      instance.SetDelete(&delete_WCSimEnumerations);
      instance.SetDeleteArray(&deleteArray_WCSimEnumerations);
      instance.SetDestructor(&destruct_WCSimEnumerations);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimEnumerations*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimEnumerations*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimEnumerations*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *WCSimEnumerations_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::WCSimEnumerations*>(nullptr))->GetClass();
      WCSimEnumerations_TClassManip(theClass);
   return theClass;
   }

   static void WCSimEnumerations_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootTrack(void *p = nullptr);
   static void *newArray_WCSimRootTrack(Long_t size, void *p);
   static void delete_WCSimRootTrack(void *p);
   static void deleteArray_WCSimRootTrack(void *p);
   static void destruct_WCSimRootTrack(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootTrack*)
   {
      ::WCSimRootTrack *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootTrack >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootTrack", ::WCSimRootTrack::Class_Version(), "WCSimRootEvent.hh", 38,
                  typeid(::WCSimRootTrack), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootTrack::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootTrack) );
      instance.SetNew(&new_WCSimRootTrack);
      instance.SetNewArray(&newArray_WCSimRootTrack);
      instance.SetDelete(&delete_WCSimRootTrack);
      instance.SetDeleteArray(&deleteArray_WCSimRootTrack);
      instance.SetDestructor(&destruct_WCSimRootTrack);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootTrack*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootTrack*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootTrack*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootCherenkovHit(void *p = nullptr);
   static void *newArray_WCSimRootCherenkovHit(Long_t size, void *p);
   static void delete_WCSimRootCherenkovHit(void *p);
   static void deleteArray_WCSimRootCherenkovHit(void *p);
   static void destruct_WCSimRootCherenkovHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootCherenkovHit*)
   {
      ::WCSimRootCherenkovHit *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootCherenkovHit >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootCherenkovHit", ::WCSimRootCherenkovHit::Class_Version(), "WCSimRootEvent.hh", 125,
                  typeid(::WCSimRootCherenkovHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootCherenkovHit::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootCherenkovHit) );
      instance.SetNew(&new_WCSimRootCherenkovHit);
      instance.SetNewArray(&newArray_WCSimRootCherenkovHit);
      instance.SetDelete(&delete_WCSimRootCherenkovHit);
      instance.SetDeleteArray(&deleteArray_WCSimRootCherenkovHit);
      instance.SetDestructor(&destruct_WCSimRootCherenkovHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootCherenkovHit*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootCherenkovHit*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootCherenkovHit*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootCherenkovHitTime(void *p = nullptr);
   static void *newArray_WCSimRootCherenkovHitTime(Long_t size, void *p);
   static void delete_WCSimRootCherenkovHitTime(void *p);
   static void deleteArray_WCSimRootCherenkovHitTime(void *p);
   static void destruct_WCSimRootCherenkovHitTime(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootCherenkovHitTime*)
   {
      ::WCSimRootCherenkovHitTime *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootCherenkovHitTime >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootCherenkovHitTime", ::WCSimRootCherenkovHitTime::Class_Version(), "WCSimRootEvent.hh", 161,
                  typeid(::WCSimRootCherenkovHitTime), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootCherenkovHitTime::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootCherenkovHitTime) );
      instance.SetNew(&new_WCSimRootCherenkovHitTime);
      instance.SetNewArray(&newArray_WCSimRootCherenkovHitTime);
      instance.SetDelete(&delete_WCSimRootCherenkovHitTime);
      instance.SetDeleteArray(&deleteArray_WCSimRootCherenkovHitTime);
      instance.SetDestructor(&destruct_WCSimRootCherenkovHitTime);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootCherenkovHitTime*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootCherenkovHitTime*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootCherenkovHitTime*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootCherenkovHitHistory(void *p = nullptr);
   static void *newArray_WCSimRootCherenkovHitHistory(Long_t size, void *p);
   static void delete_WCSimRootCherenkovHitHistory(void *p);
   static void deleteArray_WCSimRootCherenkovHitHistory(void *p);
   static void destruct_WCSimRootCherenkovHitHistory(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootCherenkovHitHistory*)
   {
      ::WCSimRootCherenkovHitHistory *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootCherenkovHitHistory >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootCherenkovHitHistory", ::WCSimRootCherenkovHitHistory::Class_Version(), "WCSimRootEvent.hh", 208,
                  typeid(::WCSimRootCherenkovHitHistory), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootCherenkovHitHistory::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootCherenkovHitHistory) );
      instance.SetNew(&new_WCSimRootCherenkovHitHistory);
      instance.SetNewArray(&newArray_WCSimRootCherenkovHitHistory);
      instance.SetDelete(&delete_WCSimRootCherenkovHitHistory);
      instance.SetDeleteArray(&deleteArray_WCSimRootCherenkovHitHistory);
      instance.SetDestructor(&destruct_WCSimRootCherenkovHitHistory);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootCherenkovHitHistory*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootCherenkovHitHistory*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootCherenkovHitHistory*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootCherenkovDigiHit(void *p = nullptr);
   static void *newArray_WCSimRootCherenkovDigiHit(Long_t size, void *p);
   static void delete_WCSimRootCherenkovDigiHit(void *p);
   static void deleteArray_WCSimRootCherenkovDigiHit(void *p);
   static void destruct_WCSimRootCherenkovDigiHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootCherenkovDigiHit*)
   {
      ::WCSimRootCherenkovDigiHit *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootCherenkovDigiHit >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootCherenkovDigiHit", ::WCSimRootCherenkovDigiHit::Class_Version(), "WCSimRootEvent.hh", 238,
                  typeid(::WCSimRootCherenkovDigiHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootCherenkovDigiHit::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootCherenkovDigiHit) );
      instance.SetNew(&new_WCSimRootCherenkovDigiHit);
      instance.SetNewArray(&newArray_WCSimRootCherenkovDigiHit);
      instance.SetDelete(&delete_WCSimRootCherenkovDigiHit);
      instance.SetDeleteArray(&deleteArray_WCSimRootCherenkovDigiHit);
      instance.SetDestructor(&destruct_WCSimRootCherenkovDigiHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootCherenkovDigiHit*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootCherenkovDigiHit*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootCherenkovDigiHit*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootEventHeader(void *p = nullptr);
   static void *newArray_WCSimRootEventHeader(Long_t size, void *p);
   static void delete_WCSimRootEventHeader(void *p);
   static void deleteArray_WCSimRootEventHeader(void *p);
   static void destruct_WCSimRootEventHeader(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootEventHeader*)
   {
      ::WCSimRootEventHeader *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootEventHeader >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootEventHeader", ::WCSimRootEventHeader::Class_Version(), "WCSimRootEvent.hh", 277,
                  typeid(::WCSimRootEventHeader), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootEventHeader::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootEventHeader) );
      instance.SetNew(&new_WCSimRootEventHeader);
      instance.SetNewArray(&newArray_WCSimRootEventHeader);
      instance.SetDelete(&delete_WCSimRootEventHeader);
      instance.SetDeleteArray(&deleteArray_WCSimRootEventHeader);
      instance.SetDestructor(&destruct_WCSimRootEventHeader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootEventHeader*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootEventHeader*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootEventHeader*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootPi0(void *p = nullptr);
   static void *newArray_WCSimRootPi0(Long_t size, void *p);
   static void delete_WCSimRootPi0(void *p);
   static void deleteArray_WCSimRootPi0(void *p);
   static void destruct_WCSimRootPi0(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootPi0*)
   {
      ::WCSimRootPi0 *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootPi0 >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootPi0", ::WCSimRootPi0::Class_Version(), "WCSimRootEvent.hh", 306,
                  typeid(::WCSimRootPi0), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootPi0::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootPi0) );
      instance.SetNew(&new_WCSimRootPi0);
      instance.SetNewArray(&newArray_WCSimRootPi0);
      instance.SetDelete(&delete_WCSimRootPi0);
      instance.SetDeleteArray(&deleteArray_WCSimRootPi0);
      instance.SetDestructor(&destruct_WCSimRootPi0);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootPi0*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootPi0*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootPi0*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootCaptureGamma(void *p = nullptr);
   static void *newArray_WCSimRootCaptureGamma(Long_t size, void *p);
   static void delete_WCSimRootCaptureGamma(void *p);
   static void deleteArray_WCSimRootCaptureGamma(void *p);
   static void destruct_WCSimRootCaptureGamma(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootCaptureGamma*)
   {
      ::WCSimRootCaptureGamma *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootCaptureGamma >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootCaptureGamma", ::WCSimRootCaptureGamma::Class_Version(), "WCSimRootEvent.hh", 341,
                  typeid(::WCSimRootCaptureGamma), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootCaptureGamma::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootCaptureGamma) );
      instance.SetNew(&new_WCSimRootCaptureGamma);
      instance.SetNewArray(&newArray_WCSimRootCaptureGamma);
      instance.SetDelete(&delete_WCSimRootCaptureGamma);
      instance.SetDeleteArray(&deleteArray_WCSimRootCaptureGamma);
      instance.SetDestructor(&destruct_WCSimRootCaptureGamma);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootCaptureGamma*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootCaptureGamma*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootCaptureGamma*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootCapture(void *p = nullptr);
   static void *newArray_WCSimRootCapture(Long_t size, void *p);
   static void delete_WCSimRootCapture(void *p);
   static void deleteArray_WCSimRootCapture(void *p);
   static void destruct_WCSimRootCapture(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootCapture*)
   {
      ::WCSimRootCapture *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootCapture >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootCapture", ::WCSimRootCapture::Class_Version(), "WCSimRootEvent.hh", 371,
                  typeid(::WCSimRootCapture), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootCapture::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootCapture) );
      instance.SetNew(&new_WCSimRootCapture);
      instance.SetNewArray(&newArray_WCSimRootCapture);
      instance.SetDelete(&delete_WCSimRootCapture);
      instance.SetDeleteArray(&deleteArray_WCSimRootCapture);
      instance.SetDestructor(&destruct_WCSimRootCapture);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootCapture*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootCapture*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootCapture*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootTrigger(void *p = nullptr);
   static void *newArray_WCSimRootTrigger(Long_t size, void *p);
   static void delete_WCSimRootTrigger(void *p);
   static void deleteArray_WCSimRootTrigger(void *p);
   static void destruct_WCSimRootTrigger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootTrigger*)
   {
      ::WCSimRootTrigger *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootTrigger >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootTrigger", ::WCSimRootTrigger::Class_Version(), "WCSimRootEvent.hh", 427,
                  typeid(::WCSimRootTrigger), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootTrigger::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootTrigger) );
      instance.SetNew(&new_WCSimRootTrigger);
      instance.SetNewArray(&newArray_WCSimRootTrigger);
      instance.SetDelete(&delete_WCSimRootTrigger);
      instance.SetDeleteArray(&deleteArray_WCSimRootTrigger);
      instance.SetDestructor(&destruct_WCSimRootTrigger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootTrigger*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootTrigger*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootTrigger*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootEvent(void *p = nullptr);
   static void *newArray_WCSimRootEvent(Long_t size, void *p);
   static void delete_WCSimRootEvent(void *p);
   static void deleteArray_WCSimRootEvent(void *p);
   static void destruct_WCSimRootEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootEvent*)
   {
      ::WCSimRootEvent *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootEvent >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootEvent", ::WCSimRootEvent::Class_Version(), "WCSimRootEvent.hh", 614,
                  typeid(::WCSimRootEvent), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootEvent::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootEvent) );
      instance.SetNew(&new_WCSimRootEvent);
      instance.SetNewArray(&newArray_WCSimRootEvent);
      instance.SetDelete(&delete_WCSimRootEvent);
      instance.SetDeleteArray(&deleteArray_WCSimRootEvent);
      instance.SetDestructor(&destruct_WCSimRootEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootEvent*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootEvent*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootEvent*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootPMT(void *p = nullptr);
   static void *newArray_WCSimRootPMT(Long_t size, void *p);
   static void delete_WCSimRootPMT(void *p);
   static void deleteArray_WCSimRootPMT(void *p);
   static void destruct_WCSimRootPMT(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootPMT*)
   {
      ::WCSimRootPMT *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootPMT >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootPMT", ::WCSimRootPMT::Class_Version(), "WCSimRootGeom.hh", 24,
                  typeid(::WCSimRootPMT), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootPMT::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootPMT) );
      instance.SetNew(&new_WCSimRootPMT);
      instance.SetNewArray(&newArray_WCSimRootPMT);
      instance.SetDelete(&delete_WCSimRootPMT);
      instance.SetDeleteArray(&deleteArray_WCSimRootPMT);
      instance.SetDestructor(&destruct_WCSimRootPMT);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootPMT*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootPMT*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootPMT*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootGeom(void *p = nullptr);
   static void *newArray_WCSimRootGeom(Long_t size, void *p);
   static void delete_WCSimRootGeom(void *p);
   static void deleteArray_WCSimRootGeom(void *p);
   static void destruct_WCSimRootGeom(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootGeom*)
   {
      ::WCSimRootGeom *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootGeom >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootGeom", ::WCSimRootGeom::Class_Version(), "WCSimRootGeom.hh", 73,
                  typeid(::WCSimRootGeom), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootGeom::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootGeom) );
      instance.SetNew(&new_WCSimRootGeom);
      instance.SetNewArray(&newArray_WCSimRootGeom);
      instance.SetDelete(&delete_WCSimRootGeom);
      instance.SetDeleteArray(&deleteArray_WCSimRootGeom);
      instance.SetDestructor(&destruct_WCSimRootGeom);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootGeom*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootGeom*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootGeom*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimPmtInfo(void *p = nullptr);
   static void *newArray_WCSimPmtInfo(Long_t size, void *p);
   static void delete_WCSimPmtInfo(void *p);
   static void deleteArray_WCSimPmtInfo(void *p);
   static void destruct_WCSimPmtInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimPmtInfo*)
   {
      ::WCSimPmtInfo *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimPmtInfo >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimPmtInfo", ::WCSimPmtInfo::Class_Version(), "WCSimPmtInfo.hh", 14,
                  typeid(::WCSimPmtInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimPmtInfo::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimPmtInfo) );
      instance.SetNew(&new_WCSimPmtInfo);
      instance.SetNewArray(&newArray_WCSimPmtInfo);
      instance.SetDelete(&delete_WCSimPmtInfo);
      instance.SetDeleteArray(&deleteArray_WCSimPmtInfo);
      instance.SetDestructor(&destruct_WCSimPmtInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimPmtInfo*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimPmtInfo*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimPmtInfo*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *WCSimDarkNoiseOptions_Dictionary();
   static void WCSimDarkNoiseOptions_TClassManip(TClass*);
   static void *new_WCSimDarkNoiseOptions(void *p = nullptr);
   static void *newArray_WCSimDarkNoiseOptions(Long_t size, void *p);
   static void delete_WCSimDarkNoiseOptions(void *p);
   static void deleteArray_WCSimDarkNoiseOptions(void *p);
   static void destruct_WCSimDarkNoiseOptions(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimDarkNoiseOptions*)
   {
      ::WCSimDarkNoiseOptions *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::WCSimDarkNoiseOptions));
      static ::ROOT::TGenericClassInfo 
         instance("WCSimDarkNoiseOptions", "WCSimRootOptions.hh", 30,
                  typeid(::WCSimDarkNoiseOptions), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &WCSimDarkNoiseOptions_Dictionary, isa_proxy, 4,
                  sizeof(::WCSimDarkNoiseOptions) );
      instance.SetNew(&new_WCSimDarkNoiseOptions);
      instance.SetNewArray(&newArray_WCSimDarkNoiseOptions);
      instance.SetDelete(&delete_WCSimDarkNoiseOptions);
      instance.SetDeleteArray(&deleteArray_WCSimDarkNoiseOptions);
      instance.SetDestructor(&destruct_WCSimDarkNoiseOptions);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimDarkNoiseOptions*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimDarkNoiseOptions*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimDarkNoiseOptions*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *WCSimDarkNoiseOptions_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::WCSimDarkNoiseOptions*>(nullptr))->GetClass();
      WCSimDarkNoiseOptions_TClassManip(theClass);
   return theClass;
   }

   static void WCSimDarkNoiseOptions_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_WCSimRootOptions(void *p = nullptr);
   static void *newArray_WCSimRootOptions(Long_t size, void *p);
   static void delete_WCSimRootOptions(void *p);
   static void deleteArray_WCSimRootOptions(void *p);
   static void destruct_WCSimRootOptions(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WCSimRootOptions*)
   {
      ::WCSimRootOptions *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WCSimRootOptions >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("WCSimRootOptions", ::WCSimRootOptions::Class_Version(), "WCSimRootOptions.hh", 54,
                  typeid(::WCSimRootOptions), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::WCSimRootOptions::Dictionary, isa_proxy, 4,
                  sizeof(::WCSimRootOptions) );
      instance.SetNew(&new_WCSimRootOptions);
      instance.SetNewArray(&newArray_WCSimRootOptions);
      instance.SetDelete(&delete_WCSimRootOptions);
      instance.SetDeleteArray(&deleteArray_WCSimRootOptions);
      instance.SetDestructor(&destruct_WCSimRootOptions);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WCSimRootOptions*)
   {
      return GenerateInitInstanceLocal(static_cast<::WCSimRootOptions*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::WCSimRootOptions*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_RooTrackerVtxBase(void *p = nullptr);
   static void *newArray_RooTrackerVtxBase(Long_t size, void *p);
   static void delete_RooTrackerVtxBase(void *p);
   static void deleteArray_RooTrackerVtxBase(void *p);
   static void destruct_RooTrackerVtxBase(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RooTrackerVtxBase*)
   {
      ::RooTrackerVtxBase *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RooTrackerVtxBase >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RooTrackerVtxBase", ::RooTrackerVtxBase::Class_Version(), "TJNuBeamFlux.hh", 18,
                  typeid(::RooTrackerVtxBase), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RooTrackerVtxBase::Dictionary, isa_proxy, 4,
                  sizeof(::RooTrackerVtxBase) );
      instance.SetNew(&new_RooTrackerVtxBase);
      instance.SetNewArray(&newArray_RooTrackerVtxBase);
      instance.SetDelete(&delete_RooTrackerVtxBase);
      instance.SetDeleteArray(&deleteArray_RooTrackerVtxBase);
      instance.SetDestructor(&destruct_RooTrackerVtxBase);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RooTrackerVtxBase*)
   {
      return GenerateInitInstanceLocal(static_cast<::RooTrackerVtxBase*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RooTrackerVtxBase*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_JNuBeamFlux(void *p = nullptr);
   static void *newArray_JNuBeamFlux(Long_t size, void *p);
   static void delete_JNuBeamFlux(void *p);
   static void deleteArray_JNuBeamFlux(void *p);
   static void destruct_JNuBeamFlux(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JNuBeamFlux*)
   {
      ::JNuBeamFlux *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JNuBeamFlux >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("JNuBeamFlux", ::JNuBeamFlux::Class_Version(), "TJNuBeamFlux.hh", 25,
                  typeid(::JNuBeamFlux), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::JNuBeamFlux::Dictionary, isa_proxy, 4,
                  sizeof(::JNuBeamFlux) );
      instance.SetNew(&new_JNuBeamFlux);
      instance.SetNewArray(&newArray_JNuBeamFlux);
      instance.SetDelete(&delete_JNuBeamFlux);
      instance.SetDeleteArray(&deleteArray_JNuBeamFlux);
      instance.SetDestructor(&destruct_JNuBeamFlux);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JNuBeamFlux*)
   {
      return GenerateInitInstanceLocal(static_cast<::JNuBeamFlux*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::JNuBeamFlux*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_NRooTrackerVtx(void *p = nullptr);
   static void *newArray_NRooTrackerVtx(Long_t size, void *p);
   static void delete_NRooTrackerVtx(void *p);
   static void deleteArray_NRooTrackerVtx(void *p);
   static void destruct_NRooTrackerVtx(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::NRooTrackerVtx*)
   {
      ::NRooTrackerVtx *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::NRooTrackerVtx >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("NRooTrackerVtx", ::NRooTrackerVtx::Class_Version(), "TNRooTrackerVtx.hh", 51,
                  typeid(::NRooTrackerVtx), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::NRooTrackerVtx::Dictionary, isa_proxy, 4,
                  sizeof(::NRooTrackerVtx) );
      instance.SetNew(&new_NRooTrackerVtx);
      instance.SetNewArray(&newArray_NRooTrackerVtx);
      instance.SetDelete(&delete_NRooTrackerVtx);
      instance.SetDeleteArray(&deleteArray_NRooTrackerVtx);
      instance.SetDestructor(&destruct_NRooTrackerVtx);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::NRooTrackerVtx*)
   {
      return GenerateInitInstanceLocal(static_cast<::NRooTrackerVtx*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::NRooTrackerVtx*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootTrack::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootTrack::Class_Name()
{
   return "WCSimRootTrack";
}

//______________________________________________________________________________
const char *WCSimRootTrack::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootTrack*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootTrack::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootTrack*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootTrack::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootTrack*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootTrack::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootTrack*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootCherenkovHit::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootCherenkovHit::Class_Name()
{
   return "WCSimRootCherenkovHit";
}

//______________________________________________________________________________
const char *WCSimRootCherenkovHit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHit*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootCherenkovHit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHit*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootCherenkovHit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHit*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootCherenkovHit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHit*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootCherenkovHitTime::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootCherenkovHitTime::Class_Name()
{
   return "WCSimRootCherenkovHitTime";
}

//______________________________________________________________________________
const char *WCSimRootCherenkovHitTime::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHitTime*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootCherenkovHitTime::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHitTime*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootCherenkovHitTime::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHitTime*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootCherenkovHitTime::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHitTime*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootCherenkovHitHistory::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootCherenkovHitHistory::Class_Name()
{
   return "WCSimRootCherenkovHitHistory";
}

//______________________________________________________________________________
const char *WCSimRootCherenkovHitHistory::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHitHistory*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootCherenkovHitHistory::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHitHistory*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootCherenkovHitHistory::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHitHistory*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootCherenkovHitHistory::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovHitHistory*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootCherenkovDigiHit::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootCherenkovDigiHit::Class_Name()
{
   return "WCSimRootCherenkovDigiHit";
}

//______________________________________________________________________________
const char *WCSimRootCherenkovDigiHit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovDigiHit*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootCherenkovDigiHit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovDigiHit*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootCherenkovDigiHit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovDigiHit*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootCherenkovDigiHit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCherenkovDigiHit*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootEventHeader::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootEventHeader::Class_Name()
{
   return "WCSimRootEventHeader";
}

//______________________________________________________________________________
const char *WCSimRootEventHeader::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootEventHeader*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootEventHeader::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootEventHeader*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootEventHeader::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootEventHeader*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootEventHeader::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootEventHeader*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootPi0::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootPi0::Class_Name()
{
   return "WCSimRootPi0";
}

//______________________________________________________________________________
const char *WCSimRootPi0::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootPi0*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootPi0::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootPi0*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootPi0::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootPi0*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootPi0::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootPi0*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootCaptureGamma::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootCaptureGamma::Class_Name()
{
   return "WCSimRootCaptureGamma";
}

//______________________________________________________________________________
const char *WCSimRootCaptureGamma::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCaptureGamma*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootCaptureGamma::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCaptureGamma*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootCaptureGamma::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCaptureGamma*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootCaptureGamma::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCaptureGamma*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootCapture::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootCapture::Class_Name()
{
   return "WCSimRootCapture";
}

//______________________________________________________________________________
const char *WCSimRootCapture::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCapture*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootCapture::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCapture*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootCapture::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCapture*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootCapture::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootCapture*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootTrigger::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootTrigger::Class_Name()
{
   return "WCSimRootTrigger";
}

//______________________________________________________________________________
const char *WCSimRootTrigger::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootTrigger*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootTrigger::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootTrigger*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootTrigger::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootTrigger*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootTrigger::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootTrigger*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootEvent::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootEvent::Class_Name()
{
   return "WCSimRootEvent";
}

//______________________________________________________________________________
const char *WCSimRootEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootEvent*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootEvent*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootEvent*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootEvent::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootEvent*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootPMT::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootPMT::Class_Name()
{
   return "WCSimRootPMT";
}

//______________________________________________________________________________
const char *WCSimRootPMT::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootPMT*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootPMT::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootPMT*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootPMT::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootPMT*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootPMT::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootPMT*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootGeom::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootGeom::Class_Name()
{
   return "WCSimRootGeom";
}

//______________________________________________________________________________
const char *WCSimRootGeom::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootGeom*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootGeom::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootGeom*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootGeom::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootGeom*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootGeom::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootGeom*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimPmtInfo::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimPmtInfo::Class_Name()
{
   return "WCSimPmtInfo";
}

//______________________________________________________________________________
const char *WCSimPmtInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimPmtInfo*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimPmtInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimPmtInfo*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimPmtInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimPmtInfo*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimPmtInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimPmtInfo*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr WCSimRootOptions::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *WCSimRootOptions::Class_Name()
{
   return "WCSimRootOptions";
}

//______________________________________________________________________________
const char *WCSimRootOptions::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootOptions*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int WCSimRootOptions::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootOptions*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WCSimRootOptions::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootOptions*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WCSimRootOptions::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WCSimRootOptions*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr RooTrackerVtxBase::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *RooTrackerVtxBase::Class_Name()
{
   return "RooTrackerVtxBase";
}

//______________________________________________________________________________
const char *RooTrackerVtxBase::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RooTrackerVtxBase*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int RooTrackerVtxBase::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RooTrackerVtxBase*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RooTrackerVtxBase::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RooTrackerVtxBase*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RooTrackerVtxBase::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RooTrackerVtxBase*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr JNuBeamFlux::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JNuBeamFlux::Class_Name()
{
   return "JNuBeamFlux";
}

//______________________________________________________________________________
const char *JNuBeamFlux::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JNuBeamFlux*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JNuBeamFlux::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JNuBeamFlux*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JNuBeamFlux::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JNuBeamFlux*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JNuBeamFlux::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JNuBeamFlux*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr NRooTrackerVtx::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *NRooTrackerVtx::Class_Name()
{
   return "NRooTrackerVtx";
}

//______________________________________________________________________________
const char *NRooTrackerVtx::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::NRooTrackerVtx*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int NRooTrackerVtx::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::NRooTrackerVtx*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *NRooTrackerVtx::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::NRooTrackerVtx*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *NRooTrackerVtx::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::NRooTrackerVtx*)nullptr)->GetClass(); }
   return fgIsA;
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEstringcOWCSimDarkNoiseOptionsgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) pair<string,WCSimDarkNoiseOptions> : new pair<string,WCSimDarkNoiseOptions>;
   }
   static void *newArray_pairlEstringcOWCSimDarkNoiseOptionsgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) pair<string,WCSimDarkNoiseOptions>[nElements] : new pair<string,WCSimDarkNoiseOptions>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEstringcOWCSimDarkNoiseOptionsgR(void *p) {
      delete (static_cast<pair<string,WCSimDarkNoiseOptions>*>(p));
   }
   static void deleteArray_pairlEstringcOWCSimDarkNoiseOptionsgR(void *p) {
      delete [] (static_cast<pair<string,WCSimDarkNoiseOptions>*>(p));
   }
   static void destruct_pairlEstringcOWCSimDarkNoiseOptionsgR(void *p) {
      typedef pair<string,WCSimDarkNoiseOptions> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class pair<string,WCSimDarkNoiseOptions>

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimEnumerations(void *p) {
      return  p ? new(p) ::WCSimEnumerations : new ::WCSimEnumerations;
   }
   static void *newArray_WCSimEnumerations(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimEnumerations[nElements] : new ::WCSimEnumerations[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimEnumerations(void *p) {
      delete (static_cast<::WCSimEnumerations*>(p));
   }
   static void deleteArray_WCSimEnumerations(void *p) {
      delete [] (static_cast<::WCSimEnumerations*>(p));
   }
   static void destruct_WCSimEnumerations(void *p) {
      typedef ::WCSimEnumerations current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimEnumerations

//______________________________________________________________________________
void WCSimRootTrack::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootTrack.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootTrack::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootTrack::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootTrack(void *p) {
      return  p ? new(p) ::WCSimRootTrack : new ::WCSimRootTrack;
   }
   static void *newArray_WCSimRootTrack(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootTrack[nElements] : new ::WCSimRootTrack[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootTrack(void *p) {
      delete (static_cast<::WCSimRootTrack*>(p));
   }
   static void deleteArray_WCSimRootTrack(void *p) {
      delete [] (static_cast<::WCSimRootTrack*>(p));
   }
   static void destruct_WCSimRootTrack(void *p) {
      typedef ::WCSimRootTrack current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootTrack

//______________________________________________________________________________
void WCSimRootCherenkovHit::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootCherenkovHit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootCherenkovHit::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootCherenkovHit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootCherenkovHit(void *p) {
      return  p ? new(p) ::WCSimRootCherenkovHit : new ::WCSimRootCherenkovHit;
   }
   static void *newArray_WCSimRootCherenkovHit(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootCherenkovHit[nElements] : new ::WCSimRootCherenkovHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootCherenkovHit(void *p) {
      delete (static_cast<::WCSimRootCherenkovHit*>(p));
   }
   static void deleteArray_WCSimRootCherenkovHit(void *p) {
      delete [] (static_cast<::WCSimRootCherenkovHit*>(p));
   }
   static void destruct_WCSimRootCherenkovHit(void *p) {
      typedef ::WCSimRootCherenkovHit current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootCherenkovHit

//______________________________________________________________________________
void WCSimRootCherenkovHitTime::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootCherenkovHitTime.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootCherenkovHitTime::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootCherenkovHitTime::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootCherenkovHitTime(void *p) {
      return  p ? new(p) ::WCSimRootCherenkovHitTime : new ::WCSimRootCherenkovHitTime;
   }
   static void *newArray_WCSimRootCherenkovHitTime(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootCherenkovHitTime[nElements] : new ::WCSimRootCherenkovHitTime[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootCherenkovHitTime(void *p) {
      delete (static_cast<::WCSimRootCherenkovHitTime*>(p));
   }
   static void deleteArray_WCSimRootCherenkovHitTime(void *p) {
      delete [] (static_cast<::WCSimRootCherenkovHitTime*>(p));
   }
   static void destruct_WCSimRootCherenkovHitTime(void *p) {
      typedef ::WCSimRootCherenkovHitTime current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootCherenkovHitTime

//______________________________________________________________________________
void WCSimRootCherenkovHitHistory::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootCherenkovHitHistory.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootCherenkovHitHistory::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootCherenkovHitHistory::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootCherenkovHitHistory(void *p) {
      return  p ? new(p) ::WCSimRootCherenkovHitHistory : new ::WCSimRootCherenkovHitHistory;
   }
   static void *newArray_WCSimRootCherenkovHitHistory(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootCherenkovHitHistory[nElements] : new ::WCSimRootCherenkovHitHistory[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootCherenkovHitHistory(void *p) {
      delete (static_cast<::WCSimRootCherenkovHitHistory*>(p));
   }
   static void deleteArray_WCSimRootCherenkovHitHistory(void *p) {
      delete [] (static_cast<::WCSimRootCherenkovHitHistory*>(p));
   }
   static void destruct_WCSimRootCherenkovHitHistory(void *p) {
      typedef ::WCSimRootCherenkovHitHistory current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootCherenkovHitHistory

//______________________________________________________________________________
void WCSimRootCherenkovDigiHit::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootCherenkovDigiHit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootCherenkovDigiHit::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootCherenkovDigiHit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootCherenkovDigiHit(void *p) {
      return  p ? new(p) ::WCSimRootCherenkovDigiHit : new ::WCSimRootCherenkovDigiHit;
   }
   static void *newArray_WCSimRootCherenkovDigiHit(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootCherenkovDigiHit[nElements] : new ::WCSimRootCherenkovDigiHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootCherenkovDigiHit(void *p) {
      delete (static_cast<::WCSimRootCherenkovDigiHit*>(p));
   }
   static void deleteArray_WCSimRootCherenkovDigiHit(void *p) {
      delete [] (static_cast<::WCSimRootCherenkovDigiHit*>(p));
   }
   static void destruct_WCSimRootCherenkovDigiHit(void *p) {
      typedef ::WCSimRootCherenkovDigiHit current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootCherenkovDigiHit

//______________________________________________________________________________
void WCSimRootEventHeader::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootEventHeader.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootEventHeader::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootEventHeader::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootEventHeader(void *p) {
      return  p ? new(p) ::WCSimRootEventHeader : new ::WCSimRootEventHeader;
   }
   static void *newArray_WCSimRootEventHeader(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootEventHeader[nElements] : new ::WCSimRootEventHeader[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootEventHeader(void *p) {
      delete (static_cast<::WCSimRootEventHeader*>(p));
   }
   static void deleteArray_WCSimRootEventHeader(void *p) {
      delete [] (static_cast<::WCSimRootEventHeader*>(p));
   }
   static void destruct_WCSimRootEventHeader(void *p) {
      typedef ::WCSimRootEventHeader current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootEventHeader

//______________________________________________________________________________
void WCSimRootPi0::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootPi0.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootPi0::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootPi0::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootPi0(void *p) {
      return  p ? new(p) ::WCSimRootPi0 : new ::WCSimRootPi0;
   }
   static void *newArray_WCSimRootPi0(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootPi0[nElements] : new ::WCSimRootPi0[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootPi0(void *p) {
      delete (static_cast<::WCSimRootPi0*>(p));
   }
   static void deleteArray_WCSimRootPi0(void *p) {
      delete [] (static_cast<::WCSimRootPi0*>(p));
   }
   static void destruct_WCSimRootPi0(void *p) {
      typedef ::WCSimRootPi0 current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootPi0

//______________________________________________________________________________
void WCSimRootCaptureGamma::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootCaptureGamma.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootCaptureGamma::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootCaptureGamma::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootCaptureGamma(void *p) {
      return  p ? new(p) ::WCSimRootCaptureGamma : new ::WCSimRootCaptureGamma;
   }
   static void *newArray_WCSimRootCaptureGamma(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootCaptureGamma[nElements] : new ::WCSimRootCaptureGamma[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootCaptureGamma(void *p) {
      delete (static_cast<::WCSimRootCaptureGamma*>(p));
   }
   static void deleteArray_WCSimRootCaptureGamma(void *p) {
      delete [] (static_cast<::WCSimRootCaptureGamma*>(p));
   }
   static void destruct_WCSimRootCaptureGamma(void *p) {
      typedef ::WCSimRootCaptureGamma current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootCaptureGamma

//______________________________________________________________________________
void WCSimRootCapture::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootCapture.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootCapture::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootCapture::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootCapture(void *p) {
      return  p ? new(p) ::WCSimRootCapture : new ::WCSimRootCapture;
   }
   static void *newArray_WCSimRootCapture(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootCapture[nElements] : new ::WCSimRootCapture[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootCapture(void *p) {
      delete (static_cast<::WCSimRootCapture*>(p));
   }
   static void deleteArray_WCSimRootCapture(void *p) {
      delete [] (static_cast<::WCSimRootCapture*>(p));
   }
   static void destruct_WCSimRootCapture(void *p) {
      typedef ::WCSimRootCapture current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootCapture

//______________________________________________________________________________
void WCSimRootTrigger::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootTrigger.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootTrigger::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootTrigger::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootTrigger(void *p) {
      return  p ? new(p) ::WCSimRootTrigger : new ::WCSimRootTrigger;
   }
   static void *newArray_WCSimRootTrigger(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootTrigger[nElements] : new ::WCSimRootTrigger[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootTrigger(void *p) {
      delete (static_cast<::WCSimRootTrigger*>(p));
   }
   static void deleteArray_WCSimRootTrigger(void *p) {
      delete [] (static_cast<::WCSimRootTrigger*>(p));
   }
   static void destruct_WCSimRootTrigger(void *p) {
      typedef ::WCSimRootTrigger current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootTrigger

//______________________________________________________________________________
void WCSimRootEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootEvent(void *p) {
      return  p ? new(p) ::WCSimRootEvent : new ::WCSimRootEvent;
   }
   static void *newArray_WCSimRootEvent(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootEvent[nElements] : new ::WCSimRootEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootEvent(void *p) {
      delete (static_cast<::WCSimRootEvent*>(p));
   }
   static void deleteArray_WCSimRootEvent(void *p) {
      delete [] (static_cast<::WCSimRootEvent*>(p));
   }
   static void destruct_WCSimRootEvent(void *p) {
      typedef ::WCSimRootEvent current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootEvent

//______________________________________________________________________________
void WCSimRootPMT::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootPMT.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootPMT::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootPMT::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootPMT(void *p) {
      return  p ? new(p) ::WCSimRootPMT : new ::WCSimRootPMT;
   }
   static void *newArray_WCSimRootPMT(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootPMT[nElements] : new ::WCSimRootPMT[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootPMT(void *p) {
      delete (static_cast<::WCSimRootPMT*>(p));
   }
   static void deleteArray_WCSimRootPMT(void *p) {
      delete [] (static_cast<::WCSimRootPMT*>(p));
   }
   static void destruct_WCSimRootPMT(void *p) {
      typedef ::WCSimRootPMT current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootPMT

//______________________________________________________________________________
void WCSimRootGeom::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootGeom.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootGeom::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootGeom::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootGeom(void *p) {
      return  p ? new(p) ::WCSimRootGeom : new ::WCSimRootGeom;
   }
   static void *newArray_WCSimRootGeom(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootGeom[nElements] : new ::WCSimRootGeom[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootGeom(void *p) {
      delete (static_cast<::WCSimRootGeom*>(p));
   }
   static void deleteArray_WCSimRootGeom(void *p) {
      delete [] (static_cast<::WCSimRootGeom*>(p));
   }
   static void destruct_WCSimRootGeom(void *p) {
      typedef ::WCSimRootGeom current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootGeom

//______________________________________________________________________________
void WCSimPmtInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimPmtInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimPmtInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimPmtInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimPmtInfo(void *p) {
      return  p ? new(p) ::WCSimPmtInfo : new ::WCSimPmtInfo;
   }
   static void *newArray_WCSimPmtInfo(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimPmtInfo[nElements] : new ::WCSimPmtInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimPmtInfo(void *p) {
      delete (static_cast<::WCSimPmtInfo*>(p));
   }
   static void deleteArray_WCSimPmtInfo(void *p) {
      delete [] (static_cast<::WCSimPmtInfo*>(p));
   }
   static void destruct_WCSimPmtInfo(void *p) {
      typedef ::WCSimPmtInfo current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimPmtInfo

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimDarkNoiseOptions(void *p) {
      return  p ? new(p) ::WCSimDarkNoiseOptions : new ::WCSimDarkNoiseOptions;
   }
   static void *newArray_WCSimDarkNoiseOptions(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimDarkNoiseOptions[nElements] : new ::WCSimDarkNoiseOptions[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimDarkNoiseOptions(void *p) {
      delete (static_cast<::WCSimDarkNoiseOptions*>(p));
   }
   static void deleteArray_WCSimDarkNoiseOptions(void *p) {
      delete [] (static_cast<::WCSimDarkNoiseOptions*>(p));
   }
   static void destruct_WCSimDarkNoiseOptions(void *p) {
      typedef ::WCSimDarkNoiseOptions current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimDarkNoiseOptions

//______________________________________________________________________________
void WCSimRootOptions::Streamer(TBuffer &R__b)
{
   // Stream an object of class WCSimRootOptions.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WCSimRootOptions::Class(),this);
   } else {
      R__b.WriteClassBuffer(WCSimRootOptions::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WCSimRootOptions(void *p) {
      return  p ? new(p) ::WCSimRootOptions : new ::WCSimRootOptions;
   }
   static void *newArray_WCSimRootOptions(Long_t nElements, void *p) {
      return p ? new(p) ::WCSimRootOptions[nElements] : new ::WCSimRootOptions[nElements];
   }
   // Wrapper around operator delete
   static void delete_WCSimRootOptions(void *p) {
      delete (static_cast<::WCSimRootOptions*>(p));
   }
   static void deleteArray_WCSimRootOptions(void *p) {
      delete [] (static_cast<::WCSimRootOptions*>(p));
   }
   static void destruct_WCSimRootOptions(void *p) {
      typedef ::WCSimRootOptions current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::WCSimRootOptions

//______________________________________________________________________________
void RooTrackerVtxBase::Streamer(TBuffer &R__b)
{
   // Stream an object of class RooTrackerVtxBase.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RooTrackerVtxBase::Class(),this);
   } else {
      R__b.WriteClassBuffer(RooTrackerVtxBase::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_RooTrackerVtxBase(void *p) {
      return  p ? new(p) ::RooTrackerVtxBase : new ::RooTrackerVtxBase;
   }
   static void *newArray_RooTrackerVtxBase(Long_t nElements, void *p) {
      return p ? new(p) ::RooTrackerVtxBase[nElements] : new ::RooTrackerVtxBase[nElements];
   }
   // Wrapper around operator delete
   static void delete_RooTrackerVtxBase(void *p) {
      delete (static_cast<::RooTrackerVtxBase*>(p));
   }
   static void deleteArray_RooTrackerVtxBase(void *p) {
      delete [] (static_cast<::RooTrackerVtxBase*>(p));
   }
   static void destruct_RooTrackerVtxBase(void *p) {
      typedef ::RooTrackerVtxBase current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RooTrackerVtxBase

//______________________________________________________________________________
void JNuBeamFlux::Streamer(TBuffer &R__b)
{
   // Stream an object of class JNuBeamFlux.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JNuBeamFlux::Class(),this);
   } else {
      R__b.WriteClassBuffer(JNuBeamFlux::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_JNuBeamFlux(void *p) {
      return  p ? new(p) ::JNuBeamFlux : new ::JNuBeamFlux;
   }
   static void *newArray_JNuBeamFlux(Long_t nElements, void *p) {
      return p ? new(p) ::JNuBeamFlux[nElements] : new ::JNuBeamFlux[nElements];
   }
   // Wrapper around operator delete
   static void delete_JNuBeamFlux(void *p) {
      delete (static_cast<::JNuBeamFlux*>(p));
   }
   static void deleteArray_JNuBeamFlux(void *p) {
      delete [] (static_cast<::JNuBeamFlux*>(p));
   }
   static void destruct_JNuBeamFlux(void *p) {
      typedef ::JNuBeamFlux current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::JNuBeamFlux

//______________________________________________________________________________
void NRooTrackerVtx::Streamer(TBuffer &R__b)
{
   // Stream an object of class NRooTrackerVtx.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(NRooTrackerVtx::Class(),this);
   } else {
      R__b.WriteClassBuffer(NRooTrackerVtx::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_NRooTrackerVtx(void *p) {
      return  p ? new(p) ::NRooTrackerVtx : new ::NRooTrackerVtx;
   }
   static void *newArray_NRooTrackerVtx(Long_t nElements, void *p) {
      return p ? new(p) ::NRooTrackerVtx[nElements] : new ::NRooTrackerVtx[nElements];
   }
   // Wrapper around operator delete
   static void delete_NRooTrackerVtx(void *p) {
      delete (static_cast<::NRooTrackerVtx*>(p));
   }
   static void deleteArray_NRooTrackerVtx(void *p) {
      delete [] (static_cast<::NRooTrackerVtx*>(p));
   }
   static void destruct_NRooTrackerVtx(void *p) {
      typedef ::NRooTrackerVtx current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::NRooTrackerVtx

namespace ROOT {
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary();
   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p);
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<float> >*)
   {
      vector<vector<float> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<float> >", -2, "vector", 425,
                  typeid(vector<vector<float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<float> >) );
      instance.SetNew(&new_vectorlEvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<float> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<vector<float> >","std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<vector<float> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<vector<float> >*>(nullptr))->GetClass();
      vectorlEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<float> > : new vector<vector<float> >;
   }
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<float> >[nElements] : new vector<vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete (static_cast<vector<vector<float> >*>(p));
   }
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete [] (static_cast<vector<vector<float> >*>(p));
   }
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p) {
      typedef vector<vector<float> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<vector<float> >

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = nullptr);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 425,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr))->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete (static_cast<vector<int>*>(p));
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] (static_cast<vector<int>*>(p));
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = nullptr);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 425,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<float>","std::vector<float, std::allocator<float> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr))->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete (static_cast<vector<float>*>(p));
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] (static_cast<vector<float>*>(p));
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = nullptr);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 425,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr))->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete (static_cast<vector<double>*>(p));
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] (static_cast<vector<double>*>(p));
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlEEReflectionSurfacegR_Dictionary();
   static void vectorlEEReflectionSurfacegR_TClassManip(TClass*);
   static void *new_vectorlEEReflectionSurfacegR(void *p = nullptr);
   static void *newArray_vectorlEEReflectionSurfacegR(Long_t size, void *p);
   static void delete_vectorlEEReflectionSurfacegR(void *p);
   static void deleteArray_vectorlEEReflectionSurfacegR(void *p);
   static void destruct_vectorlEEReflectionSurfacegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<EReflectionSurface>*)
   {
      vector<EReflectionSurface> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<EReflectionSurface>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<EReflectionSurface>", -2, "vector", 425,
                  typeid(vector<EReflectionSurface>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEEReflectionSurfacegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<EReflectionSurface>) );
      instance.SetNew(&new_vectorlEEReflectionSurfacegR);
      instance.SetNewArray(&newArray_vectorlEEReflectionSurfacegR);
      instance.SetDelete(&delete_vectorlEEReflectionSurfacegR);
      instance.SetDeleteArray(&deleteArray_vectorlEEReflectionSurfacegR);
      instance.SetDestructor(&destruct_vectorlEEReflectionSurfacegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<EReflectionSurface> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<EReflectionSurface>","std::vector<EReflectionSurface, std::allocator<EReflectionSurface> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<EReflectionSurface>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEEReflectionSurfacegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<EReflectionSurface>*>(nullptr))->GetClass();
      vectorlEEReflectionSurfacegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEEReflectionSurfacegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEEReflectionSurfacegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<EReflectionSurface> : new vector<EReflectionSurface>;
   }
   static void *newArray_vectorlEEReflectionSurfacegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<EReflectionSurface>[nElements] : new vector<EReflectionSurface>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEEReflectionSurfacegR(void *p) {
      delete (static_cast<vector<EReflectionSurface>*>(p));
   }
   static void deleteArray_vectorlEEReflectionSurfacegR(void *p) {
      delete [] (static_cast<vector<EReflectionSurface>*>(p));
   }
   static void destruct_vectorlEEReflectionSurfacegR(void *p) {
      typedef vector<EReflectionSurface> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<EReflectionSurface>

namespace ROOT {
   static TClass *maplEstringcOWCSimDarkNoiseOptionsgR_Dictionary();
   static void maplEstringcOWCSimDarkNoiseOptionsgR_TClassManip(TClass*);
   static void *new_maplEstringcOWCSimDarkNoiseOptionsgR(void *p = nullptr);
   static void *newArray_maplEstringcOWCSimDarkNoiseOptionsgR(Long_t size, void *p);
   static void delete_maplEstringcOWCSimDarkNoiseOptionsgR(void *p);
   static void deleteArray_maplEstringcOWCSimDarkNoiseOptionsgR(void *p);
   static void destruct_maplEstringcOWCSimDarkNoiseOptionsgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,WCSimDarkNoiseOptions>*)
   {
      map<string,WCSimDarkNoiseOptions> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,WCSimDarkNoiseOptions>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,WCSimDarkNoiseOptions>", -2, "map", 102,
                  typeid(map<string,WCSimDarkNoiseOptions>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOWCSimDarkNoiseOptionsgR_Dictionary, isa_proxy, 4,
                  sizeof(map<string,WCSimDarkNoiseOptions>) );
      instance.SetNew(&new_maplEstringcOWCSimDarkNoiseOptionsgR);
      instance.SetNewArray(&newArray_maplEstringcOWCSimDarkNoiseOptionsgR);
      instance.SetDelete(&delete_maplEstringcOWCSimDarkNoiseOptionsgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOWCSimDarkNoiseOptionsgR);
      instance.SetDestructor(&destruct_maplEstringcOWCSimDarkNoiseOptionsgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,WCSimDarkNoiseOptions> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<string,WCSimDarkNoiseOptions>","std::map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, WCSimDarkNoiseOptions, std::less<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, WCSimDarkNoiseOptions> > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<string,WCSimDarkNoiseOptions>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOWCSimDarkNoiseOptionsgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<string,WCSimDarkNoiseOptions>*>(nullptr))->GetClass();
      maplEstringcOWCSimDarkNoiseOptionsgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOWCSimDarkNoiseOptionsgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOWCSimDarkNoiseOptionsgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<string,WCSimDarkNoiseOptions> : new map<string,WCSimDarkNoiseOptions>;
   }
   static void *newArray_maplEstringcOWCSimDarkNoiseOptionsgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<string,WCSimDarkNoiseOptions>[nElements] : new map<string,WCSimDarkNoiseOptions>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOWCSimDarkNoiseOptionsgR(void *p) {
      delete (static_cast<map<string,WCSimDarkNoiseOptions>*>(p));
   }
   static void deleteArray_maplEstringcOWCSimDarkNoiseOptionsgR(void *p) {
      delete [] (static_cast<map<string,WCSimDarkNoiseOptions>*>(p));
   }
   static void destruct_maplEstringcOWCSimDarkNoiseOptionsgR(void *p) {
      typedef map<string,WCSimDarkNoiseOptions> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<string,WCSimDarkNoiseOptions>

namespace {
  void TriggerDictionaryInitialization_libWCSimRoot_Impl() {
    static const char* headers[] = {
"jhfNtuple.h",
"WCSimRootEvent.hh",
"WCSimRootGeom.hh",
"WCSimPmtInfo.hh",
"WCSimEnumerations.hh",
"WCSimRootOptions.hh",
"WCSimRootTools.hh",
"TJNuBeamFlux.hh",
"TNRooTrackerVtx.hh",
nullptr
    };
    static const char* includePaths[] = {
"/pbs/software/redhat-9-x86_64/hepmc3/3.2.4/include",
"/pbs/software/redhat-9-x86_64/root/6.30.06/include/root",
"/pbs/software/redhat-9-x86_64/geant4/10.04.p02/include/Geant4",
"/usr/include",
"/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/include",
"/pbs/home/m/mferey/WCSim/v1.12.8/WCSim/src",
"/pbs/software/redhat-9-x86_64/root/6.30.06/include/root",
"/pbs/home/m/mferey/WCSim/v1.12.8/build/src/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libWCSimRoot dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace std{template <typename _CharT> struct __attribute__((annotate("$clingAutoload$bits/char_traits.h")))  __attribute__((annotate("$clingAutoload$string")))  char_traits;
}
namespace std{template <typename > class __attribute__((annotate("$clingAutoload$bits/memoryfwd.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$WCSimEnumerations.hh")))  __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimEnumerations;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootTrack;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootCherenkovHit;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootCherenkovHitTime;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootCherenkovHitHistory;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootCherenkovDigiHit;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootEventHeader;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootPi0;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootCaptureGamma;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootCapture;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootTrigger;
class __attribute__((annotate("$clingAutoload$WCSimRootEvent.hh")))  WCSimRootEvent;
class __attribute__((annotate("$clingAutoload$WCSimRootGeom.hh")))  WCSimRootPMT;
class __attribute__((annotate("$clingAutoload$WCSimRootGeom.hh")))  WCSimRootGeom;
class __attribute__((annotate("$clingAutoload$WCSimPmtInfo.hh")))  WCSimPmtInfo;
class __attribute__((annotate("$clingAutoload$WCSimRootOptions.hh")))  WCSimRootOptions;
class __attribute__((annotate("$clingAutoload$TJNuBeamFlux.hh")))  RooTrackerVtxBase;
class __attribute__((annotate("$clingAutoload$TJNuBeamFlux.hh")))  JNuBeamFlux;
class __attribute__((annotate("$clingAutoload$TNRooTrackerVtx.hh")))  NRooTrackerVtx;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libWCSimRoot dictionary payload"

#ifndef USE_CPP11
  #define USE_CPP11 1
#endif
#ifndef G4_STORE_TRAJECTORY
  #define G4_STORE_TRAJECTORY 1
#endif
#ifndef G4UI_USE
  #define G4UI_USE 1
#endif
#ifndef G4VIS_USE
  #define G4VIS_USE 1
#endif
#ifndef G4UI_USE_TCSH
  #define G4UI_USE_TCSH 1
#endif
#ifndef G4INTY_USE_XT
  #define G4INTY_USE_XT 1
#endif
#ifndef G4VIS_USE_RAYTRACERX
  #define G4VIS_USE_RAYTRACERX 1
#endif
#ifndef G4INTY_USE_QT
  #define G4INTY_USE_QT 1
#endif
#ifndef G4UI_USE_QT
  #define G4UI_USE_QT 1
#endif
#ifndef G4VIS_USE_OPENGLQT
  #define G4VIS_USE_OPENGLQT 1
#endif
#ifndef G4UI_USE_XM
  #define G4UI_USE_XM 1
#endif
#ifndef G4VIS_USE_OPENGLXM
  #define G4VIS_USE_OPENGLXM 1
#endif
#ifndef G4VIS_USE_OPENGLX
  #define G4VIS_USE_OPENGLX 1
#endif
#ifndef G4VIS_USE_OPENGL
  #define G4VIS_USE_OPENGL 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "jhfNtuple.h"
#include "WCSimRootEvent.hh"
#include "WCSimRootGeom.hh"
#include "WCSimPmtInfo.hh"
#include "WCSimEnumerations.hh"
#include "WCSimRootOptions.hh"
#include "WCSimRootTools.hh"
#include "TJNuBeamFlux.hh"
#include "TNRooTrackerVtx.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"JNuBeamFlux", payloadCode, "@",
"NRooTrackerVtx", payloadCode, "@",
"RooTrackerVtxBase", payloadCode, "@",
"WCSimDarkNoiseOptions", payloadCode, "@",
"WCSimEnumerations", payloadCode, "@",
"WCSimPmtInfo", payloadCode, "@",
"WCSimRootCapture", payloadCode, "@",
"WCSimRootCaptureGamma", payloadCode, "@",
"WCSimRootCherenkovDigiHit", payloadCode, "@",
"WCSimRootCherenkovHit", payloadCode, "@",
"WCSimRootCherenkovHitHistory", payloadCode, "@",
"WCSimRootCherenkovHitTime", payloadCode, "@",
"WCSimRootEvent", payloadCode, "@",
"WCSimRootEventHeader", payloadCode, "@",
"WCSimRootGeom", payloadCode, "@",
"WCSimRootOptions", payloadCode, "@",
"WCSimRootPMT", payloadCode, "@",
"WCSimRootPi0", payloadCode, "@",
"WCSimRootTrack", payloadCode, "@",
"WCSimRootTrigger", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libWCSimRoot",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libWCSimRoot_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libWCSimRoot_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libWCSimRoot() {
  TriggerDictionaryInitialization_libWCSimRoot_Impl();
}
