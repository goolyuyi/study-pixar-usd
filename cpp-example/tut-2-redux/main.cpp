//
// Created by 于一 on 2022/9/2.
//

//domain-specific interfaces?

#include <iostream>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usdGeom/sphere.h>


///```python
///from pxr import Usd
///stage = Usd.Stage.CreateNew('HelloWorldRedux.usda')
///xform = stage.DefinePrim('/hello', 'Xform')
///sphere = stage.DefinePrim('/hello/world', 'Sphere')
///stage.GetRootLayer().Save()
///```

///Note that UsdGeomXform::Define returns a schema object on which the full schema-specific API is available, as opposed to UsdStage::DefinePrim which returns a generic UsdPrim. In USD, all schema classes have a GetPrim() member function that returns its underlying UsdPrim. Think of a UsdPrim as the object’s generic, persistent presence in the scenegraph, and the schema object as the first-class way to access its domain-specific data and functionality.

int main() {
    using namespace pxr;
    const auto stage = UsdStage::CreateNew("HelloWorldRedux.usda");
    auto xformPrim = stage->DefinePrim(SdfPath{"/hello"}, TfToken{"Xform"});
    auto spherePrim = stage->DefinePrim(SdfPath{"/hello/world"}, TfToken{"Sphere"});
    stage->GetRootLayer()->Save();
}

