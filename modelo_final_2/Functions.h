
#define LOW_LIMIT 1
#define HI_LIMIT 999999999

/**
 * \brief Solicita un numero de deposito origen y destino al usuario y valida que no sean iguales
 * \param (void)
 * \return (int) El numero del deposito origen ingresado por el usuario
 */
int getValidDesposit(void);


/**
 * \brief Solicita un codigo de producto al usuario y valida que exista en la lista de productos
 * \param depositList (ArrayList*) Puntero a la lista de productos
 * \return (Product*) El producto con el codigo ingresado por el usuario
 */
Product* getValidProduct(ArrayList* depositList);


/**
 * \brief Mueve el producto pasado como parametro desde el deposito origen al deposito destino
 * \param depositOriginList (ArrayList*) Puntero al deposito origen 
 * \param depositDestinoList (ArrayList*) Puntero al deposito destino
 * \param productToMove (Product*) Puntero al producto a ser trasladado 
 * \return (void)
 */
void moveProductToDeposit(ArrayList* depositOriginList, ArrayList* depositDestinoList, Product* productToMove);


/**
 * \brief Descuenta del stock del producto la cantidad pasada como parametro
 * \param stockAux (int) Stock del producto del que se va a descontar cantidad
 * \param qtyToDiscount (int) Cantidad que se va a descontar del stock del producto
 * \param productToModifyStock (Product*) Puntero al producto del que se va a descontar el stock
 * \return (void)
 */
void discountProductStock(int stockAux, int qtyToDiscount, Product *productToModifyStock);


/**
 * \brief Agrega al stock del producto la cantidad pasada como parametro
 * \param stockAux (int) Stock del producto al que se va a agregar cantidad
 * \param qtyToAdd (int) Cantidad que se va a agregar al stock del producto
 * \param productToModifyStock (Product*) Puntero al producto al que se va a agregar el stock
 * \return (void)
 */
void addProductStock(int stockAux, int qtyToAdd, Product *productToModifyStock);

