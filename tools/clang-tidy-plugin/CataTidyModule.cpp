#include <llvm/ADT/StringRef.h>

#include "AlmostNeverAutoCheck.h"
#include "AssertCheck.h"
#include "ClangTidyModule.h"
#include "ClangTidyModuleRegistry.h"
#include "CombineLocalsIntoPointCheck.h"
#include "DeterminismCheck.h"
#include "HeaderGuardCheck.h"
#include "JsonTranslationInputCheck.h"
#include "NoLongCheck.h"
#include "NoStaticGettextCheck.h"
#include "PointInitializationCheck.h"
#include "SimplifyPointConstructorsCheck.h"
#include "StaticDeclarationsCheck.h"
#include "StaticStringIdConstantsCheck.h"
#include "TestFilenameCheck.h"
#include "TestsMustRestoreGlobalStateCheck.h"
#include "TextStyleCheck.h"
#include "TranslatorCommentsCheck.h"
#include "UseLocalizedSortingCheck.h"
#include "UseNamedPointConstantsCheck.h"
#include "UsePointApisCheck.h"
#include "UsePointArithmeticCheck.h"
#include "XYCheck.h"

namespace clang
{
namespace tidy
{
namespace cata
{

class CataModule : public ClangTidyModule
{
    public:
        void addCheckFactories( ClangTidyCheckFactories &CheckFactories ) override {
            CheckFactories.registerCheck<AlmostNeverAutoCheck>( "cata-almost-never-auto" );
            CheckFactories.registerCheck<AssertCheck>( "cata-assert" );
            CheckFactories.registerCheck<CombineLocalsIntoPointCheck>(
                "cata-combine-locals-into-point" );
            CheckFactories.registerCheck<DeterminismCheck>( "cata-determinism" );
            CheckFactories.registerCheck<CataHeaderGuardCheck>( "cata-header-guard" );
            CheckFactories.registerCheck<JsonTranslationInputCheck>( "cata-json-translation-input" );
            CheckFactories.registerCheck<NoLongCheck>( "cata-no-long" );
            CheckFactories.registerCheck<NoStaticGettextCheck>( "cata-no-static-gettext" );
            CheckFactories.registerCheck<PointInitializationCheck>( "cata-point-initialization" );
            CheckFactories.registerCheck<SimplifyPointConstructorsCheck>(
                "cata-simplify-point-constructors" );
            CheckFactories.registerCheck<StaticDeclarationsCheck>( "cata-static-declarations" );
            CheckFactories.registerCheck<StaticStringIdConstantsCheck>(
                "cata-static-string_id-constants" );
            CheckFactories.registerCheck<TestFilenameCheck>( "cata-test-filename" );
            CheckFactories.registerCheck<TestsMustRestoreGlobalStateCheck>(
                "cata-tests-must-restore-global-state" );
            CheckFactories.registerCheck<TextStyleCheck>( "cata-text-style" );
            CheckFactories.registerCheck<TranslatorCommentsCheck>( "cata-translator-comments" );
            CheckFactories.registerCheck<UseLocalizedSortingCheck>( "cata-use-localized-sorting" );
            CheckFactories.registerCheck<UseNamedPointConstantsCheck>(
                "cata-use-named-point-constants" );
            CheckFactories.registerCheck<UsePointApisCheck>( "cata-use-point-apis" );
            CheckFactories.registerCheck<UsePointArithmeticCheck>( "cata-use-point-arithmetic" );
            CheckFactories.registerCheck<XYCheck>( "cata-xy" );
        }
};

} // namespace cata

// Register the MiscTidyModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<cata::CataModule>
X( "cata-module", "Adds Cataclysm-DDA checks." );

} // namespace tidy
} // namespace clang
