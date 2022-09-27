//
// Created by 于一 on 2022/9/2.
//
#include <iostream>
#include <iomanip>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/usdGeom/mesh.h>
#include <pxr/usd/usdGeom/primvarsAPI.h>

int main() {
    using namespace pxr;
    using namespace std;
    const auto book_stage = UsdStage::Open("../examples-usd/Book/Book.usd");

    cout << "------Traverse All-----------\n";
    for (const auto &item: book_stage->TraverseAll()) {
        cout << left << setw(40) << item.GetPath() << setw(20) << item.GetTypeName() << endl;
    }

    cout << "------pCube Attributes-----------\n";
    const auto pCube = book_stage->GetPrimAtPath(SdfPath("/Book/Geom/pCube134"));
    for (const auto &item: pCube.GetAttributes()) {
        cout << item.GetName() << endl;
    }

    const auto extent = pCube.GetAttribute(TfToken("extent"));

    for (const auto &item: extent.GetAllMetadata())
        cout << item.first << ":" << item.second << endl;
    
    cout << "------points-----------\n";
    const auto points = pCube.GetAttribute(TfToken("points"));
    cout << points.GetTypeName() << "\n";
    VtArray<GfVec3f> v;
    cout << boolalpha << points.Get(&v) << "\n";
    cout << "got length of data: " << v.size() << "\n";

    cout << "------meta-----------\n";
    cout << book_stage->HasMetadata(TfToken("upAxis")) << "\n";

    for (const auto &item: book_stage->GetPseudoRoot().GetAllMetadata()) {
        cout << item.first << ":" << item.second << endl;
    }

    cout << "------/Book meta-----------\n";
    const auto book_prim = book_stage->GetPrimAtPath(SdfPath("/Book"));
    for (const auto &item: book_prim.GetAllMetadata()) {
        cout << item.first << ":" << item.second << endl;
    }


    cout << "------primvar-----------\n";
    const auto pCube_primvar = UsdGeomPrimvarsAPI(pCube);
    for (const auto &item: pCube_primvar.GetPrimvarsWithValues()) {
        cout << item.GetName() << endl;
    }

    cout << "------primvar st-----------\n";
    const auto st = UsdGeomPrimvar(pCube.GetAttribute(TfToken("primvars:st")));

    cout << "\n GetElementSize: " << st.GetElementSize()
         << "\n GetTypeName: " << st.GetTypeName()
         << "\n GetPrimvarName: " << st.GetPrimvarName()
         << "\n GetInterpolation: " << st.GetInterpolation()
         << endl;

    VtArray<GfVec2f> st_value;
    st.Get(&st_value);

    VtIntArray st_indices;
    st.GetIndices(&st_indices);

    for (auto i = 0; i < st_value.size(); i++) {
        cout << st_value[i] << "/" << st_indices[i] << " ";
    }
}

