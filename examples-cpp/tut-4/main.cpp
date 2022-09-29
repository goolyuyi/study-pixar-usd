//
// Created by 于一 on 2022/9/24.
//

#include <iostream>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/sdf/layer.h>
#include <pxr/usd/sdf/path.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/sdf/primSpec.h>
#include <pxr/usd/usd/primDefinition.h>
#include <pxr/usd/usd/variantSets.h>

int main(int, char *[]) {
    using namespace pxr;
    using namespace std;

    const auto stage = UsdStage::Open("tut-4-usd/1-sublayer-or-local/subs.usd");
    for (const auto &item: stage->Traverse()) {
        cout << item.GetPath() << "\n";
    }
    const auto code = stage->GetPrimAtPath(SdfPath("/Code"));
    const auto code_def = code.GetPrimDefinition();
    //code.ComputeExpandedPrimIndex()
    //code.GetPrimIndex()
    const auto code_attr = code.GetAttribute(TfToken("attr"));
    const auto code_stack = code.GetPrimStack();
    for (const auto &item: code_stack) {
        SdfPrimSpec sps = item.GetSpec();
        cout << sps.GetName() << "\n";
        SdfLayer &sps_layer = *sps.GetLayer();
        cout << sps_layer.GetRealPath() << "\n";
    }


}