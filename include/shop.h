#ifndef GUARD_SHOP_H
#define GUARD_SHOP_H

extern struct ItemSlot gMartPurchaseHistory[3];

void CreatePokemartMenu(const u16 *itemsForSale, u8 martType);
void CreateDecorationShopMenu(const u16 *itemsForSale, u8 martType);
void CB2_ExitSellMenu(void);

#endif // GUARD_SHOP_H
