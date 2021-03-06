#ifndef UtilAlgos_FunctionMinSelector_h
#define UtilAlgos_FunctionMinSelector_h

#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"
#include "CommonTools/UtilAlgos/interface/ParameterAdapter.h"
#include "CommonTools/Utils/interface/FunctionMinSelector.h"
#include "CommonTools/RecoAlgos/plugins/SuperClusterEt.h"

namespace reco {
   namespace modules {
     typedef FunctionMinSelector<SuperClusterEt> EtMinSuperClusterSelector;

     template<>
     struct ParameterAdapter<EtMinSuperClusterSelector> {
       static EtMinSuperClusterSelector make(
         const edm::ParameterSet & cfg, edm::ConsumesCollector & iC ) {
	 return EtMinSuperClusterSelector( cfg.getParameter<double>( "etMin" ) );
       }

       static void fillPSetDescription(edm::ParameterSetDescription& desc) {
         desc.add<double>("etMin", 0);
       }
     };

   }
}

#endif
