//
// Created by 于一 on 2022/9/24.
//

#include <iostream>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/sdf/layer.h>
#include <pxr/usd/sdf/path.h>
#include <pxr/usd/usdGeom/xform.h>

int main(int, char *[]) {
    using namespace pxr;
    using namespace std;

    SdfPath path{"/hello"};
    path.AppendChild(TfToken("world"));


    cout << path.GetAsToken().GetString() << endl;
    const auto stage_temp = UsdStage::CreateNew("tut_temp.usda");
    auto aprim = stage_temp->DefinePrim(path, TfToken{"Xform"});
    auto astack = aprim.GetPrimStack();
    auto sdfdesc = astack[0];

    auto xform = UsdGeomXform(aprim);
    auto props = aprim.GetProperties();

    auto attr = aprim.CreateAttribute(TfToken("test_matrix"), SdfValueTypeNames->Matrix4d);
    attr.Set(GfMatrix4d{1});
    sdfdesc->WriteToStream(cout);

}
