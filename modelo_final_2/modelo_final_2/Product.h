
#ifndef __Product
#define __Product
struct{

    int productId;
    char description[51];
    int stock;

}typedef Product;
#endif // __Product


/** \brief Allocate a new product.
 * \param void
 * \return Product* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new product) if ok
 */
Product* product_new(void);


/** \brief Set pProduct Product the id recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param productId (int) Id recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setId(Product* pProduct, int productId, int lowLimit);


/** \brief Set pProduct Product the description recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param description (char*) Pointer to the description recived
 * \param lowLimit (int) Lower limit allowed
 * \param hiLimit (int) Higher limit allowed
 * \return int Return (-1) if Error [Invalid Id]
 *                  - ( 0) if Ok
 */
int product_setDescription(Product* pProduct, char* description, int lowLimit, int hiLimit);


/** \brief Set pProduct Product the stock recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \param stock (int) Stock recived
 * \param lowLimit (int) Lower limit allowed
 * \return int Return (-1) if Error [Invalid stock]
 *                  - ( 0) if Ok
 */
int product_setStock(Product* pProduct, int stock, int lowLimit);



/** \brief  Get the id of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Id of the product
 */
int product_getId(Product* pProduct);



/** \brief  Get the description of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Description of the product
 */
char* product_getDescription(Product* pProduct);



/** \brief  Get the stock of the product recived as parameter
 * \param pProduct (Product*)* Pointer to the product
 * \return (int) Stock of the product
 */
int product_getStock(Product* pProduct);



/** \brief Shows the selected product by screen
 * \param pProduct (Product*) Pointer to the product to be displayed
 * \return void
 */
void product_print(Product* pProduct);



/** \brief Shows all the product in the list of products
 * \param productsList (ArrayList*) Pointer to the list of products to be displayed
 * \return int Return (-1) if Error [Empty list]
 *                  - (0) if Ok
 */
int product_printArrayList(ArrayList* productsList);
