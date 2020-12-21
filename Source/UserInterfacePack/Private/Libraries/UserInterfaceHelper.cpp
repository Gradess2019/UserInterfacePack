// Gradess Games. All rights reserved.

#include "Libraries/UserInterfaceHelper.h"
#include "Components/SizeBox.h"
#include "Components/Border.h"
#include "Components/ComboBoxString.h"

void UUserInterfaceHelper::SetTint(FSlateBrush& SlateBrush, FSlateColor Color)
{
	SlateBrush.TintColor = Color;
}

void UUserInterfaceHelper::SetButtonTint(
	FButtonStyle& ButtonStyle,
	FButtonColorData ColorData
)
{
	SetTint(ButtonStyle.Normal, ColorData.Normal);
	SetTint(ButtonStyle.Hovered, ColorData.Hovered);
	SetTint(ButtonStyle.Pressed, ColorData.Pressed);
}

void UUserInterfaceHelper::SetComboBoxTintWidget(
	UUserWidget* OwnerWidget,
	UComboBoxString* ComboBox,
	FComboBoxColorData ColorData
)
{
	if (!IsValid(ComboBox)) { return; }

	SetComboBoxTint(
		OwnerWidget,
		ComboBox->WidgetStyle.ComboButtonStyle,
		ComboBox->ItemStyle,
		ColorData
	);
}

void UUserInterfaceHelper::SetComboBoxTint(
	UUserWidget* OwnerWidget,
	FComboButtonStyle& ComboButtonStyle,
	FTableRowStyle& ItemStyle,
	FComboBoxColorData ColorData
)
{
	SetButtonTint(
		ComboButtonStyle.ButtonStyle,
		ColorData.Button
	);

	SetTint(ComboButtonStyle.DownArrowImage, ColorData.DownArrow);
	SetTint(ComboButtonStyle.MenuBorderBrush, ColorData.MenuBorder);

	SetTint(ItemStyle.ActiveBrush, ColorData.Item.Active);
	SetTint(ItemStyle.ActiveHoveredBrush, ColorData.Item.ActiveHovered);
	SetTint(ItemStyle.InactiveBrush, ColorData.Item.Inactive);
	SetTint(ItemStyle.InactiveHoveredBrush, ColorData.Item.InactiveHovered);
	SetTint(ItemStyle.EvenRowBackgroundHoveredBrush, ColorData.Item.EvenRowHovered);
	SetTint(ItemStyle.OddRowBackgroundHoveredBrush, ColorData.Item.OddRowHovered);

	ItemStyle.TextColor = ColorData.Item.Text;
	ItemStyle.SelectedTextColor = ColorData.Item.SelectedText;

	if(!IsValid(OwnerWidget)) { return; }
	OwnerWidget->SetForegroundColor(ColorData.ForegroundColor);
}

void UUserInterfaceHelper::SetBorderTintWidget(UBorder* Border, FSlateColor Color)
{
	if (!IsValid(Border)) { return; }

	auto Brush = Border->Background;
	Brush.TintColor = Color;
	Border->SetBrush(Brush);
}

void UUserInterfaceHelper::SetCheckBoxTint(FCheckBoxStyle& CheckBoxStyle, FCheckBoxColorData ColorData)
{
	SetTint(CheckBoxStyle.UncheckedImage, ColorData.Unchecked);
	SetTint(CheckBoxStyle.UncheckedHoveredImage, ColorData.UncheckedHovered);
	SetTint(CheckBoxStyle.UncheckedPressedImage, ColorData.UncheckedPressed);

	SetTint(CheckBoxStyle.CheckedImage, ColorData.Checked);
	SetTint(CheckBoxStyle.CheckedHoveredImage, ColorData.CheckedHovered);
	SetTint(CheckBoxStyle.CheckedPressedImage, ColorData.CheckedPressed);

	SetTint(CheckBoxStyle.UndeterminedImage, ColorData.Undetermined);
	SetTint(CheckBoxStyle.UndeterminedHoveredImage, ColorData.UndeterminedHovered);
	SetTint(CheckBoxStyle.UndeterminedPressedImage, ColorData.UndeterminedPressed);
}

void UUserInterfaceHelper::SetSize(USizeBox* SizeBox, float Width, float Height)
{
	if (!IsValid(SizeBox)) { return; }

	SizeBox->SetWidthOverride(Width);
	SizeBox->SetHeightOverride(Height);
}
