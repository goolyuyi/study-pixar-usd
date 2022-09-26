## USD
### Tips
* authored 著有属性
  * author a property 著写(编著)属性
* UsdStage
* UsdPrim

### UsdGeom API 

-   USD's built-in geometry schema
-   These prim types and associated C++ and Python API have first-class support in USD and provide domain-specific interfaces to create, manipulate, introspect and author properties upon them.
-   In USD, all schema classes have a GetPrim() member function that returns its underlying [UsdPrim](https://graphics.pixar.com/usd/release/api/class_usd_prim.html). Think of a [UsdPrim](https://graphics.pixar.com/usd/release/api/class_usd_prim.html) as the object's generic, persistent presence in the scenegraph, and the schema object as the first-class way to access its domain-specific data and functionality.

### Attribute

-   An attribute has a fallback value when no opinions about its value are authored in the scene description. This fallback value for extent is sensible given that the fallback value for a sphere's radius is 1.0.
-   A call to Usd.Attribute.Get() with no arguments returns the attribute's value at the [Default time](https://graphics.pixar.com/usd/release/api/class_usd_time_code.html#a8a2192045dc22e90fe08ef2d8d68f3b8). 
-   UsdPrim::GetPropertyNames demonstrates that we can fetch properties by name. In practice, to iterate over a prim's properties it is generally more convenient to use one of UsdPrim::GetProperties, [UsdPrim::GetAttributes](https://graphics.pixar.com/usd/release/api/class_usd_prim.html#a07e5668bd9f88b39e3c7261d409bfcae), or [UsdPrim::GetRelationships](https://graphics.pixar.com/usd/release/api/class_usd_prim.html#aa6202f152dc043e81b648112984e936c). These return [UsdProperty](https://graphics.pixar.com/usd/release/api/class_usd_property.html), [UsdAttribute](https://graphics.pixar.com/usd/release/api/class_usd_attribute.html), and [UsdRelationship](https://graphics.pixar.com/usd/release/api/class_usd_relationship.html) objects that one can operate on directly.

### Properties
-   [UsdProperty](https://graphics.pixar.com/usd/release/api/class_usd_property.html)  provides access to authoring and interrogating properties and their common metadata

-   [UsdAttribute](https://graphics.pixar.com/usd/release/api/class_usd_attribute.html)  refines UsdProperty with specific API for time-sampled access to typed attribute data

-   [UsdRelationship](https://graphics.pixar.com/usd/release/api/class_usd_relationship.html)  refines UsdProperty with API to target other prims and properties, and resolve those targets robustly, and through chains of relationships.

-   Properties are ordered in dictionary order, by default, but one can explicitly order properties using [UsdPrim::SetPropertyOrder](https://graphics.pixar.com/usd/release/api/class_usd_prim.html#a7285692cfe69b46e890ec25756d02c37).

>In this example we use a filename to reference the layer. In practice, the layer identifier passed to Usd.References.AddReference() can be any string that a path resolver plugin can resolve and a scene description file format plugin would process to populate the actual scene description. USD supports user-implementable asset path resolver and file format plugins to allow site-specific customization and pipeline integration. USD does not require that layers be files on disk. See [the Ar library documentation](https://graphics.pixar.com/usd/release/api/ar_page_front.html) for more about asset resolvers, and see the code refXform.SetXformOpOrder([])

>we are telling the schema to ignore any ops, even if authored, effectively setting the transformation to the identity. We could also have explicitly authored an identity matrix, or set all existing, composed op attributes to their identity values. For a complete explanation of Xformable and XformOps, please see the [API documentation for UsdGeomXformable](https://graphics.pixar.com/usd/release/api/class_usd_geom_xformable.html#details)in USD/extras/usd/examples/usdObj/ for an example file format plugin.
### Reference
* `def`: which are concrete prims that appear in standard scenegraph traversals
* `over`: an over can be thought of as containing a set of _speculative opinions_ that are applied over any concrete prims that may be defined in other layers at the corresponding namespace location in a composed stage.
  * Overs can contain opinions for any property, metadata, or prim composition operators.
  * For example, an over can non-destructively express a different opinion for the transform and displayColor attributes above.
  
>In this example we use a filename to reference the layer. In practice, the layer identifier passed to Usd.References.AddReference() can be any string that a path resolver plugin can resolve and a scene description file format plugin would process to populate the actual scene description. USD supports user-implementable asset path resolver and file format plugins to allow site-specific customization and pipeline integration. USD does not require that layers be files on disk. See [the Ar library documentation](https://graphics.pixar.com/usd/release/api/ar_page_front.html) for more about asset resolvers, and see the code in USD/extras/usd/examples/usdObj/ for an example file format plugin.