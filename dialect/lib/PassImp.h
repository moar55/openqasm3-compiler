#include "mlir/Pass/Pass.h"

namespace mlir {
namespace quantum {
#define GEN_PASS_CLASSES
#include "Quantum/Transforms/Passes.h.inc"
} // namespace quantum
} // end namespace mlir