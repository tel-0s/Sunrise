#pragma once

#include <cstdint>

namespace sunrise::server::bap {

/**
 * Queues one character item (a weapon or armor piece) for the normal acquisition flow. The reward
 * is saved before anything is presented. It reaches the selected character, with its pickup
 * feedback, once the Family-4 inventory peer is active, or it settles at once when none is.
 * Called on the server thread.
 * @param itemDefinitionIndex Native dense item-definition index.
 * @return True when the reward was saved.
 */
[[nodiscard]] bool arm_world_item_acquisition(std::uint16_t itemDefinitionIndex) noexcept;

/**
 * Queues one profile material or consumable stack for the normal acquisition flow, as above.
 * @param itemDefinitionIndex Native dense item-definition index.
 * @param quantity Units to grant; must be positive.
 * @return True when the reward was saved.
 */
[[nodiscard]] bool arm_world_profile_item_acquisition(std::uint16_t itemDefinitionIndex,
                                                      std::int32_t quantity) noexcept;

} // namespace sunrise::server::bap
