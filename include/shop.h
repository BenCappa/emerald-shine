#ifndef GUARD_SHOP_H
#define GUARD_SHOP_H

extern struct ItemSlot gMartPurchaseHistory[3];

void CreatePokemartMenu(const u16 *, u8);
void CreateDecorationShopMenu(const u16 *, u8);
void CB2_ExitSellMenu(void);

#endif // GUARD_SHOP_H
