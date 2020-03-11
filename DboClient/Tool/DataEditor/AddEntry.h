#pragma once
#include "TableContainer.h"
#include "TableAll.h"
#include "ListContainer.h"

namespace DataEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	/// <summary>
	/// Summary for AddEntry
	/// </summary>
	public ref class AddEntry : public System::Windows::Forms::Form
	{
	public:
		AddEntry(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		AddEntry(sITEM_TBLDAT* sItemTable )
		{
			InitializeComponent();
			ConstructItemInsert(sItemTable);
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddEntry()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dgAddEntry;
	private: System::Windows::Forms::Button^  btnAddEntry;
	protected:


	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dgAddEntry = (gcnew System::Windows::Forms::DataGridView());
			this->btnAddEntry = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAddEntry))->BeginInit();
			this->SuspendLayout();
			// 
			// dgAddEntry
			// 
			this->dgAddEntry->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgAddEntry->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAddEntry->Location = System::Drawing::Point(10, 12);
			this->dgAddEntry->Name = L"dgAddEntry";
			this->dgAddEntry->Size = System::Drawing::Size(857, 135);
			this->dgAddEntry->TabIndex = 0;
			// 
			// btnAddEntry
			// 
			this->btnAddEntry->Location = System::Drawing::Point(12, 153);
			this->btnAddEntry->Name = L"btnAddEntry";
			this->btnAddEntry->Size = System::Drawing::Size(134, 23);
			this->btnAddEntry->TabIndex = 1;
			this->btnAddEntry->Text = L"Add Entry to Table";
			this->btnAddEntry->UseVisualStyleBackColor = true;
			//this->btnAddEntry->Click += gcnew System::EventHandler(this, &AddEntry::btnAddEntry_Click);
			// 
			// AddEntry
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(879, 188);
			this->Controls->Add(this->btnAddEntry);
			this->Controls->Add(this->dgAddEntry);
			this->Name = L"AddEntry";
			this->Text = L"Add New Entry";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAddEntry))->EndInit();
			this->ResumeLayout(false);

		}

		void ConstructItemInsert(sITEM_TBLDAT* item)
		{

			DataGridViewTextBoxColumn ^ colTblidx = gcnew DataGridViewTextBoxColumn;
			colTblidx->Name = "TBLIDX";
			dgAddEntry->Columns->Add(colTblidx);
			dgAddEntry->Rows[0]->Cells[0]->Value = item->tblidx;

			DataGridViewCheckBoxColumn ^ colValid = gcnew DataGridViewCheckBoxColumn;
			colValid->Name = "bValidityAble";
			dgAddEntry->Columns->Add(colValid);
			dgAddEntry->Rows[0]->Cells[1]->Value = item->bValidity_Able;

			DataGridViewTextBoxColumn ^ colName = gcnew DataGridViewTextBoxColumn;
			colName->Name = "Name";
			dgAddEntry->Columns->Add(colName);
			dgAddEntry->Rows[0]->Cells[2]->Value = item->Name;


			DataGridViewTextBoxColumn ^ colwszNameText = gcnew DataGridViewTextBoxColumn;
			colwszNameText->Name = "szNameText";
			dgAddEntry->Columns->Add(colwszNameText);
			std::wstring wNameText(item->wszNameText);
			dgAddEntry->Rows[0]->Cells[3]->Value = gcnew String(wNameText.c_str());


			DataGridViewTextBoxColumn ^ colszIcon_Name = gcnew DataGridViewTextBoxColumn;
			colszIcon_Name->Name = "szIcon_Name";
			dgAddEntry->Columns->Add(colszIcon_Name);
			dgAddEntry->Rows[0]->Cells[4]->Value = gcnew String(item->szIcon_Name);



			DataGridViewTextBoxColumn ^ colbyModel_Type = gcnew DataGridViewTextBoxColumn;
			colbyModel_Type->Name = "Model Type";
			dgAddEntry->Columns->Add(colbyModel_Type);
			dgAddEntry->Rows[0]->Cells[5]->Value = item->byModel_Type;

			
			DataGridViewTextBoxColumn ^ colszModel = gcnew DataGridViewTextBoxColumn;
			colszModel->Name = "szModel";
			dgAddEntry->Columns->Add(colszModel);
			dgAddEntry->Rows[0]->Cells[6]->Value = gcnew String(item->szModel);

			DataGridViewTextBoxColumn ^ colszSubWeaponModel = gcnew DataGridViewTextBoxColumn;
			colszSubWeaponModel->Name = "szSubWeaponActModel";
			dgAddEntry->Columns->Add(colszSubWeaponModel);
			dgAddEntry->Rows[0]->Cells[7]->Value = gcnew String(item->szSub_Weapon_Act_Model);

			DataGridViewTextBoxColumn ^ colByItemType = gcnew DataGridViewTextBoxColumn;
			colByItemType->Name = "byItemType";
			dgAddEntry->Columns->Add(colByItemType);
			dgAddEntry->Rows[0]->Cells[8]->Value = item->byItem_Type;

	

			DataGridViewTextBoxColumn ^ colbyEquipType = gcnew DataGridViewTextBoxColumn;
			colbyEquipType->Name = "byEquipType";
			dgAddEntry->Columns->Add(colbyEquipType);
			dgAddEntry->Rows[0]->Cells[9]->Value = item->byEquip_Type;


			DataGridViewTextBoxColumn  ^ colequipSlotBitflag = gcnew DataGridViewTextBoxColumn;
			colequipSlotBitflag->Name = "Equip Slot Flag";
			dgAddEntry->Columns->Add(colequipSlotBitflag);
			dgAddEntry->Rows[0]->Cells[10]->Value = item->wEquip_Slot_Type_Bit_Flag;
			
			DataGridViewTextBoxColumn ^ colwFuctionFlag = gcnew DataGridViewTextBoxColumn;
			colwFuctionFlag->Name = "Function Flag";
			dgAddEntry->Columns->Add(colwFuctionFlag);
			dgAddEntry->Rows[0]->Cells[11]->Value = item->wFunction_Bit_Flag;

			DataGridViewTextBoxColumn ^ colbyMaxStack = gcnew DataGridViewTextBoxColumn;
			colbyMaxStack->Name = "Max Stack";
			dgAddEntry->Columns->Add(colbyMaxStack);
			dgAddEntry->Rows[0]->Cells[12]->Value = item->byMax_Stack;

			DataGridViewTextBoxColumn ^ colbyRank = gcnew DataGridViewTextBoxColumn;
			colbyRank->Name = "Rank";
			dgAddEntry->Columns->Add(colbyRank);
			dgAddEntry->Rows[0]->Cells[13]->Value = item->byMax_Stack;

			DataGridViewTextBoxColumn ^ colCost = gcnew DataGridViewTextBoxColumn;
			colCost->Name = "Cost";
			dgAddEntry->Columns->Add(colCost);
			dgAddEntry->Rows[0]->Cells[14]->Value = item->dwCost;

			DataGridViewTextBoxColumn ^ colSellPrice= gcnew DataGridViewTextBoxColumn;
			colSellPrice->Name = "Sell Price/1000 * Cost";
			dgAddEntry->Columns->Add(colSellPrice);
			dgAddEntry->Rows[0]->Cells[15]->Value = item->bySell_Price;

			DataGridViewTextBoxColumn ^ colDurability = gcnew DataGridViewTextBoxColumn;
			colDurability->Name = "Durability";
			dgAddEntry->Columns->Add(colDurability);
			dgAddEntry->Rows[0]->Cells[16]->Value = item->byDurability;

			DataGridViewTextBoxColumn ^ colDuraCount = gcnew DataGridViewTextBoxColumn;
			colDuraCount->Name = "Dur Count";
			dgAddEntry->Columns->Add(colDuraCount);
			dgAddEntry->Rows[0]->Cells[17]->Value = item->byDurability_Count;

			DataGridViewTextBoxColumn ^ colBattleAttribute = gcnew DataGridViewTextBoxColumn;
			colBattleAttribute->Name = "Battle Attribute";
			dgAddEntry->Columns->Add(colBattleAttribute);
			dgAddEntry->Rows[0]->Cells[18]->Value = item->byBattle_Attribute;

			DataGridViewTextBoxColumn ^ colPhysOffence = gcnew DataGridViewTextBoxColumn;
			colPhysOffence->Name = "Phys Offence";
			dgAddEntry->Columns->Add(colPhysOffence);
			dgAddEntry->Rows[0]->Cells[19]->Value = item->wPhysical_Offence;

			DataGridViewTextBoxColumn ^ colEngOffence = gcnew DataGridViewTextBoxColumn;
			colEngOffence->Name = "Eng Offence";
			dgAddEntry->Columns->Add(colEngOffence);
			dgAddEntry->Rows[0]->Cells[20]->Value = item->wEnergy_Offence;

			DataGridViewTextBoxColumn ^ colPhysDefence = gcnew DataGridViewTextBoxColumn;
			colPhysDefence->Name = "Phys Defence";
			dgAddEntry->Columns->Add(colPhysDefence);
			dgAddEntry->Rows[0]->Cells[21]->Value = item->wPhysical_Defence;

			DataGridViewTextBoxColumn ^ colEngDefence = gcnew DataGridViewTextBoxColumn;
			colEngDefence->Name = "Eng Defence";
			dgAddEntry->Columns->Add(colEngDefence);
			dgAddEntry->Rows[0]->Cells[22]->Value = item->wEnergy_Defence;

			DataGridViewTextBoxColumn ^ colPhysOffUpgrade = gcnew DataGridViewTextBoxColumn;
			colPhysOffUpgrade->Name = "Phs Offense Upgrade";
			dgAddEntry->Columns->Add(colPhysOffUpgrade);
//			dgAddEntry->Rows[0]->Cells[23]->Value = item->dwPhysical_OffenceUpgrade;

			DataGridViewTextBoxColumn ^ colEngOffUpgrade = gcnew DataGridViewTextBoxColumn;
			colEngOffUpgrade->Name = "Eng Offense Upgrade";
			dgAddEntry->Columns->Add(colEngOffUpgrade);
			//dgAddEntry->Rows[0]->Cells[24]->Value = item->dwEnergy_OffenceUpgrade;

			DataGridViewTextBoxColumn ^ colPhysDefUpgrade = gcnew DataGridViewTextBoxColumn;
			colPhysDefUpgrade->Name = "Phys Defence Upgrade";
			dgAddEntry->Columns->Add(colPhysDefUpgrade);
			//dgAddEntry->Rows[0]->Cells[25]->Value = item->dwPhysical_DefenceUpgrade;

			DataGridViewTextBoxColumn ^ colEngDefUpgrade = gcnew DataGridViewTextBoxColumn;
			colEngDefUpgrade->Name = "Eng Defence Upgrade";
			dgAddEntry->Columns->Add(colEngDefUpgrade);
			//dgAddEntry->Rows[0]->Cells[26]->Value = item->dwEnergy_DefenceUpgrade;


			DataGridViewTextBoxColumn ^ colAtkRange = gcnew DataGridViewTextBoxColumn;
			colAtkRange->Name = "Attack Range";
			dgAddEntry->Columns->Add(colAtkRange);
			dgAddEntry->Rows[0]->Cells[27]->Value = item->fAttack_Range_Bonus;


			DataGridViewTextBoxColumn ^ colAtkSpd = gcnew DataGridViewTextBoxColumn;
			colAtkSpd->Name = "Attack Speed";
			dgAddEntry->Columns->Add(colAtkSpd);
			dgAddEntry->Rows[0]->Cells[28]->Value = item->wAttack_Speed_Rate;


			DataGridViewTextBoxColumn ^ colLevel = gcnew DataGridViewTextBoxColumn;
			colLevel->Name = "Level Needed";
			dgAddEntry->Columns->Add(colLevel);
			dgAddEntry->Rows[0]->Cells[29]->Value = item->byNeed_Level;


			DataGridViewTextBoxColumn ^ colClassNeeded= gcnew DataGridViewTextBoxColumn;
			colClassNeeded->Name = "Needed Class Flag";
			dgAddEntry->Columns->Add(colClassNeeded);
			dgAddEntry->Rows[0]->Cells[30]->Value = item->dwNeed_Class_Bit_Flag;


			DataGridViewTextBoxColumn ^ colClassSpecial = gcnew DataGridViewTextBoxColumn;
			colClassSpecial->Name = "Class Special";
			dgAddEntry->Columns->Add(colClassSpecial);
			dgAddEntry->Rows[0]->Cells[31]->Value = item->byClass_Special;

			DataGridViewTextBoxColumn ^ colRaceSpecial = gcnew DataGridViewTextBoxColumn;
			colRaceSpecial->Name = "Race Special";
			dgAddEntry->Columns->Add(colRaceSpecial);
			dgAddEntry->Rows[0]->Cells[32]->Value = item->byRace_Special;

			DataGridViewTextBoxColumn ^ colStr = gcnew DataGridViewTextBoxColumn;
			colStr->Name = "Str Required";
			dgAddEntry->Columns->Add(colStr);
			dgAddEntry->Rows[0]->Cells[33]->Value = item->byNeed_Str;

			DataGridViewTextBoxColumn ^ colCon= gcnew DataGridViewTextBoxColumn;
			colCon->Name = "Con Required";
			dgAddEntry->Columns->Add(colCon);
			dgAddEntry->Rows[0]->Cells[34]->Value = item->byNeed_Con;

			DataGridViewTextBoxColumn ^ colFoc= gcnew DataGridViewTextBoxColumn;
			colFoc->Name = "Foc Required";
			dgAddEntry->Columns->Add(colFoc);
			dgAddEntry->Rows[0]->Cells[35]->Value = item->byNeed_Foc;

			DataGridViewTextBoxColumn ^ colDex= gcnew DataGridViewTextBoxColumn;
			colDex->Name = "Dex Required";
			dgAddEntry->Columns->Add(colDex);
			dgAddEntry->Rows[0]->Cells[36]->Value = item->byNeed_Dex;

			DataGridViewTextBoxColumn ^ colSol= gcnew DataGridViewTextBoxColumn;
			colSol->Name = "Sol Required";
			dgAddEntry->Columns->Add(colSol);
			dgAddEntry->Rows[0]->Cells[37]->Value = item->byNeed_Sol;

			DataGridViewTextBoxColumn ^ colEng= gcnew DataGridViewTextBoxColumn;
			colEng->Name = "Eng Required";
			dgAddEntry->Columns->Add(colEng);
			dgAddEntry->Rows[0]->Cells[38]->Value = item->byNeed_Eng;

			DataGridViewTextBoxColumn ^ colSetTblidx = gcnew DataGridViewTextBoxColumn;
			colSetTblidx->Name = "Set Item Tblidx";
			dgAddEntry->Columns->Add(colSetTblidx);
			dgAddEntry->Rows[0]->Cells[39]->Value = item->set_Item_Tblidx;

			DataGridViewTextBoxColumn ^ colNoteTblidx = gcnew DataGridViewTextBoxColumn;
			colNoteTblidx->Name = "Note Tblidx";
			dgAddEntry->Columns->Add(colNoteTblidx);
			dgAddEntry->Rows[0]->Cells[40]->Value = item->Note;

			DataGridViewTextBoxColumn ^ colBagSize = gcnew DataGridViewTextBoxColumn;
			colBagSize->Name = "Bag Size";
			dgAddEntry->Columns->Add(colBagSize);
			dgAddEntry->Rows[0]->Cells[41]->Value = item->byBag_Size;

			DataGridViewTextBoxColumn ^ colWatts = gcnew DataGridViewTextBoxColumn;
			colWatts->Name = "Scouter Watts";
			dgAddEntry->Columns->Add(colWatts);
			dgAddEntry->Rows[0]->Cells[42]->Value = item->wScouter_Watt;

			DataGridViewTextBoxColumn ^ colMaxPow = gcnew DataGridViewTextBoxColumn;
			colMaxPow->Name = "Scouter MaxPower";
			dgAddEntry->Columns->Add(colMaxPow);
			dgAddEntry->Rows[0]->Cells[43]->Value = item->dwScouter_MaxPower;

			DataGridViewTextBoxColumn ^ colPartsType= gcnew DataGridViewTextBoxColumn;
			colPartsType->Name = "Scouter Parts Type";
			dgAddEntry->Columns->Add(colPartsType);
			dgAddEntry->Rows[0]->Cells[44]->Value = item->byScouter_Parts_Type;

			DataGridViewTextBoxColumn ^ colPartsValue = gcnew DataGridViewTextBoxColumn;
			colPartsValue->Name = "Scouter Parts Value";
			dgAddEntry->Columns->Add(colPartsValue);
			dgAddEntry->Rows[0]->Cells[45]->Value = item->byScouter_Parts_Type;

			DataGridViewTextBoxColumn ^ colUseTblidx = gcnew DataGridViewTextBoxColumn;
			colUseTblidx->Name = "Use Item Tblidx";
			dgAddEntry->Columns->Add(colUseTblidx);
			dgAddEntry->Rows[0]->Cells[46]->Value = item->Use_Item_Tblidx;

			DataGridViewTextBoxColumn ^ colOptionTblidx = gcnew DataGridViewTextBoxColumn;
			colOptionTblidx->Name = "Item Option Tblidx";
			dgAddEntry->Columns->Add(colOptionTblidx);
			dgAddEntry->Rows[0]->Cells[47]->Value = item->Item_Option_Tblidx;

			DataGridViewTextBoxColumn ^ colItemGroup = gcnew DataGridViewTextBoxColumn;
			colItemGroup->Name = "Item Group";
			dgAddEntry->Columns->Add(colItemGroup);
			dgAddEntry->Rows[0]->Cells[48]->Value = item->byItemGroup;

			DataGridViewTextBoxColumn ^ colCharmTblidx = gcnew DataGridViewTextBoxColumn;
			colCharmTblidx->Name = "Charm Tblidx";
			dgAddEntry->Columns->Add(colCharmTblidx);
			dgAddEntry->Rows[0]->Cells[49]->Value = item->Charm_Tblidx;

			DataGridViewTextBoxColumn ^ colHideBitflag = gcnew DataGridViewTextBoxColumn;
			colHideBitflag->Name = "Costume Hide Flag";
			dgAddEntry->Columns->Add(colHideBitflag);
			dgAddEntry->Rows[0]->Cells[50]->Value = item->wCostumeHideBitFlag;

			DataGridViewTextBoxColumn ^ colNeedItemTblidx = gcnew DataGridViewTextBoxColumn;
			colNeedItemTblidx->Name = "Need Item Tblidx";
			dgAddEntry->Columns->Add(colNeedItemTblidx);
			dgAddEntry->Rows[0]->Cells[51]->Value = item->NeedItemTblidx;

			DataGridViewTextBoxColumn ^ colNetpyPoints = gcnew DataGridViewTextBoxColumn;
			colNetpyPoints->Name = "Netpy Points";
			dgAddEntry->Columns->Add(colNetpyPoints);
			dgAddEntry->Rows[0]->Cells[52]->Value = item->CommonPoint;

			DataGridViewTextBoxColumn ^ colNetpyType = gcnew DataGridViewTextBoxColumn;
			colNetpyType->Name = "Netpy Point Type";
			dgAddEntry->Columns->Add(colNetpyType);
			dgAddEntry->Rows[0]->Cells[53]->Value = item->byCommonPointType;

			DataGridViewTextBoxColumn ^ colNeedFunction = gcnew DataGridViewTextBoxColumn;
			colNeedFunction->Name = "Need Function";
			dgAddEntry->Columns->Add(colNeedFunction);
			dgAddEntry->Rows[0]->Cells[54]->Value = item->byNeedFunction;

			DataGridViewTextBoxColumn ^ colDurationMax = gcnew DataGridViewTextBoxColumn;
			colDurationMax->Name = "Use Duration Max";
			dgAddEntry->Columns->Add(colDurationMax);
			dgAddEntry->Rows[0]->Cells[55]->Value = item->dwUseDurationMax;

			DataGridViewTextBoxColumn ^ colDurationtype = gcnew DataGridViewTextBoxColumn;
			colDurationtype->Name = "Duration Type";
			dgAddEntry->Columns->Add(colDurationtype);
			dgAddEntry->Rows[0]->Cells[56]->Value = item->byDurationType;

			DataGridViewTextBoxColumn ^ colContentsTblidx = gcnew DataGridViewTextBoxColumn;
			colContentsTblidx->Name = "Contents Tblidx";
			dgAddEntry->Columns->Add(colContentsTblidx);
			dgAddEntry->Rows[0]->Cells[57]->Value = item->contentsTblidx;

			DataGridViewTextBoxColumn ^ colDurationGroup = gcnew DataGridViewTextBoxColumn;
			colDurationGroup->Name = "Duration Group";
			dgAddEntry->Columns->Add(colDurationGroup);
			dgAddEntry->Rows[0]->Cells[58]->Value = item->dwDurationGroup;

			//dgAddEntry->Rows->Add(1);
		}
#pragma endregion
	private: System::Void cbSelectAdd_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {


	}

 public: System::Char* GetItemTypeCombo(byte byItemType)
			 {
				 switch (byItemType)
				 {
				 case ITEM_TYPE_GLOVE:
					 return L"Gloves";
				 case ITEM_TYPE_STAFF:
					 return L"Staff";
				 case ITEM_TYPE_GUN:
					 return L"Gun";
				 case ITEM_TYPE_DUAL_GUN:
					 return L"Dual Gun";
				 case ITEM_TYPE_CLAW:
					 return L"Claw";
				 case ITEM_TYPE_AXE:
					 return L"Axe";
				 case ITEM_TYPE_SCROLL:
					 return L"Scroll";
				 case ITEM_TYPE_GEM:
					 return L"Gem";
				 case ITEM_TYPE_STICK:
					 return L"Stick";
				 case ITEM_TYPE_SWORD:
					 return L"Sword";
				 case ITEM_TYPE_FAN:
					 return L"Fan";
				 case ITEM_TYPE_WAND:
					 return L"Wand";
				 case ITEM_TYPE_BAZOOKA:
					 return L"Bazooka";
				 case ITEM_TYPE_BACK_PACK:
					 return L"Back Pack";
				 case ITEM_TYPE_INSTRUMENT:
					 return L"Instrument";
				 case ITEM_TYPE_CLUB:
					 return L"Club";
				 case ITEM_TYPE_DRUM:
					 return L"Drum";
				 case ITEM_TYPE_MASK:
					 return L"Mask";

				 case ITEM_TYPE_JACKET:
					 return L"Jacket";
				 case ITEM_TYPE_PANTS:
					 return L"Pants";
				 case ITEM_TYPE_BOOTS:
					 return L"Boots";

				 case ITEM_TYPE_NECKLACE:
					 return L"Necklace";
				 case ITEM_TYPE_EARRING:
					 return L"Earring";
				 case ITEM_TYPE_RING:
					 return L"Ring";

				 case ITEM_TYPE_SCOUTER:
					 return L"Scouter";
				 case ITEM_TYPE_SCOUTER_PART:
					 return L"Scouter Part";

				// case ITEM_TYPE_COSTUME:
				//	 return L"Costume";
				 case ITEM_TYPE_BAG:
					 return L"Bag";
				 case ITEM_TYPE_QUEST:
					 return L"Quest";
				 case ITEM_TYPE_STONE:
					 return L"Stone";

				 case ITEM_TYPE_RECOVER:
					 return L"Recover";
				 case ITEM_TYPE_FOOD:
					 return L"Food";
				 case ITEM_TYPE_UTILITY:
					 return L"Utility";
				 case ITEM_TYPE_CHARM:
					 return L"Charm";
				 case ITEM_TYPE_CAPSULE:
					 return L"Capsule";
				 case ITEM_TYPE_FUEL:
					 return L"Fuel";
				 case ITEM_TYPE_JUNK:
					 return L"Junk";
				 case ITEM_TYPE_COLLECTION:
					 return L"Collection";
				 case ITEM_TYPE_WAREHOUSE:
					 return L"Warehouse";
				 case ITEM_TYPE_DRAGONBALL:
					 return L"DragonBall";
				 case ITEM_TYPE_GAMBLE:
					 return L"Gamble";
				 case ITEM_TYPE_MATERIAL:
					 return L"Material";
				 case ITEM_TYPE_RECIPE:
					 return L"Recipe";
				 case ITEM_TYPE_HOIPOIROCK:
					 return L"HoiPoiRock";
				 case ITEM_TYPE_DOGI:
					 return L"Dogi";
				 case ITEM_TYPE_PURE_STONE:
					 return L"Pure Stone";
				 case ITEM_TYPE_BLACK_STONE:
					 return L"Black Stone";
				 case ITEM_TYPE_NETPYSTORE:
					 return L"NetpyStore";
			/*	 case ITEM_TYPE_HAIR:
					 return L"Hair";
				 case ITEM_TYPE_ACCESSORY1:
					 return L"Accessory1";
				 case ITEM_TYPE_ACCESSORY2:
					 return L"Accessory2";
				 case ITEM_TYPE_ACCESSORY3:
					 return L"Accessory3";*/
				 default:
					 return L"Unknown";
				 }
			 }
public: System::Char* GetEquipTypeCombo(byte byEquipType)
{
	switch (byEquipType)
	{

	case EQUIP_TYPE_MAIN_WEAPON:
		return L"Main Weapon";
	case EQUIP_TYPE_SUB_WEAPON:
		return L"Sub Weapon";
	case EQUIP_TYPE_ARMOR:
		return L"Armor";
	case EQUIP_TYPE_SCOUTER:
		return L"Scouter";
	case EQUIP_TYPE_QUEST:
		return L"Quest";
	case EQUIP_TYPE_ACCESSORY:
		return L"Accessory";
	/*case EQUIP_TYPE_DOGI:
		return L"Dogi";
	case EQUIP_TYPE_HAIR:
		return L"Hair";
	case EQUIP_TYPE_COSTUME_ACC:
		return L"Costume Accessory";*/
	default:
		return L"unknown";
	}
}
//private: System::Void btnAddEntry_Click(System::Object^  sender, System::EventArgs^  e) {
//	CItemTable* tbldat = container->GetItemTable();
//}
};
}
